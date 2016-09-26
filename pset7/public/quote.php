<?php

    // configuration
    require("../includes/config.php"); 

     if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("quote_form.php", ["title" => "Quote"]);
    }
    
    if ($_SERVER["REQUEST_METHOD"] == "POST"){
        $stock = lookup($_POST["stock"]);
        
        if($stock == false) {
            apologize("Stock symbol not found");
        }
        else{
            $stock = lookup($_POST["stock"]);
            render("quote.php", ["title" => "Quote", "stock" => $stock]);
        }
    }
    
?>
