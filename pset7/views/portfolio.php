<span><?="Current cash = $" . number_format($cash,2)?></span>
<table>
    <tr>
        <th>Stock</th>
        <th>Shares</th>
        <th>Price</th>
        <th>Current Value</th>
    </tr>
    <?php foreach ($positions as $position): ?>
        <tr>
            <td><?= $position["symbol"] ?></td>
            <td><?= $position["shares"] ?></td>
            <td><?= '$' . $position["price"] ?></td>
            <td><?= '$' . ($position["price"]*$position["shares"]) ?></td>
        </tr>
    <?php endforeach ?>
</table>