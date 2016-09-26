<?php
$n = $_POST["height"]; // TODO what should $n really be? Replace the 10 with the user-supplied value from the form
$m = $_POST["width"];
//$width = $_POST["width"];

// if we don't have a number, redirect back to the form page
if (empty($n)) {
    header("Location: ./mult_form.php");
    exit;
}

?>

<!DOCTYPE html>
<html>
    <head>
        <title>Your Table is Ready</title>
    </head>
    <body>
        <table style = "align-center">
            <?php for ($i = 1; $i <= $n; $i++): ?>
                <!-- TODO this multiplication table needs some work! -->
                <tr>
                    <td>
                        <?php for ($j = 1; $j <= $m; $j++){
                        $product = $j * $i;
                        echo "$product  ";}?>
                    </td> 
                </tr>
            <?php endfor ?>
        </table>
    </body>
</html>