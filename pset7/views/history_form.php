<table>
    <tr>
        <th>Time</th>
        <th>Transaction</th>
        <th>Stock</th>
        <th>Shares</th>
        <th>Price</th>
    </tr>
    <?php foreach ($rows as $row): ?>
        <tr>
            <td><?= $row["time"] ?></td>
            <td><?= $row["transaction"] ?></td>
            <td><?= $row["symbol"] ?></td>
            <td><?= $row["shares"] ?></td>
            <td><?= '$' . $row["price"] ?></td>
        </tr>
    <?php endforeach ?>
</table>

