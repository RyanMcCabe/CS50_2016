<?php

    // configuration
    require("../includes/config.php"); 
    $cash = CS50::query("SELECT cash FROM users Where id = ?", $_SESSION["id"]);
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
    }
    // render portfolio
    render("portfolio.php", ["cash" => $cash[0]["cash"], "positions" => $positions, "title" => "Portfolio"]);

?>
