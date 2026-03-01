<?php
define('EMAIL_CORRETTA', 'email@gmail.com');
define('PASSWORD_CORRETTA', '12345');

$messaggio = "";

$email = htmlspecialchars(strip_tags(trim($_POST['email'] ?? '')));
$password = htmlspecialchars(strip_tags(trim($_POST['password'] ?? '')));

if ($_SERVER['REQUEST_METHOD'] == "POST") {

    if (($email !== "" && $password !== "")) {

        if (EMAIL_CORRETTA == $email && PASSWORD_CORRETTA == $password) {
            header("Location: dashboard.php?email=" . urlencode($email));
            exit();
        } else {
            $messaggio = "Credenziali errate!";
        }

    } else {
        if (empty($email) && empty($password))
            $messaggio = "Compila tutti i campi!";
        if (empty($email))
            $messaggio = "Hai dimenticato di compilare il campo: Email!";
        if (empty($password))
            $messaggio = "Hai dimenticato di compilare il campo: Password!!";
    }
}
?>

<!DOCTYPE html>
<html lang="it">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>login</title>
    <link rel="stylesheet" href="styles.css" defer>
    <script href="script.js" defer></script>
</head>

<body>
    <h1>Pagina di login semplice</h1>

    <?php if ($messaggio): ?>
        <div class="error">
            <?php echo $messaggio; ?>
        </div>
    <?php endif; ?>

    <form class="container" action="login.php" method="POST">
        <div class="emailDiv">
            <label for="email">Email:</label>
            <input type="email" value="<?= $email ?>" name="email"
                placeholder="Inserisci l'email. ex: utente@esempio.com">
        </div>

        <div class="passwordDiv">
            <label for="password">Password:</label>
            <input type="password" name="password" placeholder="Inserisci la password">
            <label for="show-hidden-password">Mostra/Nascondi</label><input type="checkbox" name="show-hidden-password">
        </div>

        <div class="submitDiv">
            <button type="submit">Accedi</button>
        </div>
    </form>
ciao
    <p style="margin-top: 20px; color: #666; font-size: 14px;">
        <em>Credenziali di test: email@gmail.com / 12345</em>
    </p>
</body>

</html>