<?php

    // configuration
    require("../includes/config.php"); 

    $rows = CS50::query("SELECT * FROM history WHERE user_id = ?", $_SESSION["id"]);
    render("history_form.php", ["rows" => $rows, "title" => "Buy"]);

?>