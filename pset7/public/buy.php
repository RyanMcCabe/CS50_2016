<?php

    // configuration
    require("../includes/config.php"); 

     if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        $rows = CS50::query("SELECT symbol, shares FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
        $positions = [];
        foreach ($rows as $row)
        {
            $stock = lookup($row["symbol"]);
            if ($stock !== false)
            {
                $positions[] = [
                    "name" => $stock["name"],
                    "price" => $stock["price"],
                    "shares" => $row["shares"],
                    "symbol" => $row["symbol"]
                ];
            }
        }render("buy_form.php", ["positions" => $positions, "title" => "Buy"]);
    }
    
    if ($_SERVER["REQUEST_METHOD"] == "POST"){
        $stock = strtoupper($_POST["stock"]);
        $stock = lookup($stock);
        
        if($stock == false) {
            apologize("Stock symbol not found");
        }
        else{
            if(!preg_match("/^\d+$/", $_POST["shares"])){
                apologize("Please enter a whole number of shares you would like to buy");
            }
            
            $stock = lookup($_POST["stock"]);
            $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
            
            $value = $stock["price"] * $_POST["shares"];
            
            if($cash[0]["cash"] < $value){
                apologize("You don't have enough money");
            }
            else{
                
                CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $value, $_SESSION["id"]);
                CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY 
                    UPDATE shares = shares + ?", $_SESSION["id"], $stock["symbol"], $_POST["shares"], $_POST["shares"]);
                
                CS50::query("INSERT into history (user_id, transaction, symbol, shares, price, time) VALUES (?, 'buy', ?, ?, ?, NOW())",
                    $_SESSION["id"], $stock["symbol"], $_POST["shares"], $stock["price"]);
                redirect("index.php");
            }
            
        }
    }
    
?>
