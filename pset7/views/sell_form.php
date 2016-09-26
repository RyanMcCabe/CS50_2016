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
<span>Select stock to sell</span>
<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
            <input autocomplete="off" autofocus class="form-control" name="stock" placeholder="Stock Symbol" type="text"/>
        </div>
       
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                Submit
            </button>
        </div>
    </fieldset>
</form>
