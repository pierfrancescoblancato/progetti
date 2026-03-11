<?php
session_start();
?>
<!DOCTYPE html>
<html lang="it">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>login</title>
    <link rel="stylesheet" href="styles.css">
    <script src="script.js" defer></script>
</head>

<body>
    <h1>Pagina di SignUp semplice</h1>

    <?php if (!empty($_SESSION['messageError'])): ?>
        <div class="error">
            <?= $_SESSION['messageError'] ?>
        </div>
        <?php unset($_SESSION['messageError']); ?>
    <?php endif; ?>

    <form class="container" action="api/apiSignUp.php" method="POST">
        <div class="emailDiv">
            <label for="email">Email:</label>
            <input type="email" name="email" placeholder="Inserisci l'email. ex: utente@esempio.com">
        </div>

        <div class="passwordDiv">
            <label for="password">Password:</label>
            <input type="password" class="password-input" id="password" name="password"
                placeholder="Inserisci la password">
            <button type="button" class="toggle-password" id="toggle-password"></button>
        </div>

        <div class="other">
            <a class="login" href="logIn.php">have you an account?</a><br>
        </div>

        <div class="submitDiv">
            <button type="submit">Accedi</button>
        </div>
    </form>

    <p><em>Credenziali di test: email@gmail.com / 12345678</em></p>
</body>

</html>
