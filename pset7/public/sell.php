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
        }render("sell_form.php", ["positions" => $positions, "title" => "Sell"]);
    }
    
    if ($_SERVER["REQUEST_METHOD"] == "POST"){
        $stock = strtoupper($_POST["stock"]);
        $stock = lookup($stock);
        
        if($stock == false) {
            apologize("Stock symbol not found");
        }
        else{
            $stock = lookup($_POST["stock"]);
            $row = CS50::query("SELECT * FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $stock["symbol"]);
            
            if($row[0]["shares"] == 0){
                apologize("You don't have that stock");
            }
            else{
                $value = $row[0]["shares"]*$stock["price"];
                CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $value, $_SESSION["id"]);
                CS50::query("DELETE FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $stock["symbol"]);
                
                 CS50::query("INSERT into history (user_id, transaction, symbol, shares, price, time) VALUES (?, 'sell', ?, ?, ?, NOW())",
                    $_SESSION["id"], $stock["symbol"], $row[0]["shares"], $stock["price"]);
                redirect("index.php");
            }
            
        }
    }
    
?>
