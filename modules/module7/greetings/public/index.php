<?php

// include the helper file
require("../includes/helpers.php");


// get all the greeting rows from the database
$greeting_rows = CS50::query("SELECT * FROM greetings");

// for debugging, just to see how the data is structured
//print("This is what we have in the database right now:");
//var_dump($greeting_rows);


// RENDER STUFF --------------------

$header_data = ["title" => "Greetings"];
render("header.php", $header_data);

$form_data = ["rows" => $greeting_rows]; // TODO add a key-value pair whose value is $greeting_rows so that we can pass it over to greeting_form.php
render("greeting_form.php", $form_data); 

render("footer.php");

?>

