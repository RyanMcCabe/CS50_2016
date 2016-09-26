<?php

// TODO replace with actual content (e.g. "Cheers, David!")
$message = "Hello, '{$name}'!";

// TODO replace 0 with the correct value
$report_num_times = "This is the '{$num_times}' time I have said '{$greeting_text}' to someone";

?>

<h2><?= htmlspecialchars($message) ?></h2>
<p><?= htmlspecialchars($report_num_times) ?></p>