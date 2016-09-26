<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("password_form.php", ["title" => "Password"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if(empty($_POST["password"])){
            apologize("Please enter a password");
        }
        else if ($_POST["password"] != $_POST["confirmation"]){
            apologize("Password and confirmation password must be the same");
        }
        else{
            CS50::query("UPDATE users SET hash = ? WHERE id = ?", password_hash($_POST["password"], PASSWORD_DEFAULT), $_SESSION["id"]);
            redirect("index.php");
            
        }
    }
        

?>