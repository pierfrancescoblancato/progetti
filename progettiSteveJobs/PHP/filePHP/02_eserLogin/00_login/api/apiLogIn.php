<?php
session_start();

if ($_SERVER['REQUEST_METHOD'] === "POST") {

    function redirectToLogInWithError($errorMessage)
    {
        $_SESSION['messageError'] = $errorMessage;
        header('Location: ../logIn.php'); 
        exit;
    }

    // 1. Sanificazione input
    $email = htmlspecialchars(strip_tags(trim($_POST['email'] ?? '')));
    $password = htmlspecialchars(strip_tags(trim($_POST['password'] ?? '')));

    if (empty($email) || !filter_var($email, FILTER_VALIDATE_EMAIL)) {
        redirectToLogInWithError("Invalid email format.");
    }
    
    if (strlen($password) < 8) {
        redirectToLogInWithError("Password must be at least 8 characters long.");
    }

    // 2. Connessione al database
    $conn = new mysqli("localhost", "root", "tua_password", "corso41");

    if ($conn->connect_error) {
        redirectToLogInWithError("Database connection failed.");
    }

    // 3. Cerchiamo l'utente nel database tramite la sua email
    $stmt = $conn->prepare("SELECT email, password FROM logData WHERE email = ?");
    $stmt->bind_param("s", $email);
    $stmt->execute();
    $result = $stmt->get_result();

    if ($user = $result->fetch_assoc()) {
        // 4. Verifichiamo la password usando password_verify
        // $user['password'] contiene l'hash salvato nel DB durante il signUp
        if (password_verify($password, $user['password'])) {
            // LOGIN SUCCESSO
            $_SESSION['email'] = $user['email'];
            header("Location: ../dashboard.php");
            exit();
        } else {
            redirectToLogInWithError("Incorrect password.");
        }
    } else {
        redirectToLogInWithError("No user found with this email.");
    }

    $stmt->close();
    $conn->close();
}
?>