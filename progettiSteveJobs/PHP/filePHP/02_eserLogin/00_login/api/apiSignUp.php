<?php

if ($_SERVER['REQUEST_METHOD'] === 'POST') {

session_start();

    function redirectToSignupWithError($errorMessage)
    {
        $_SESSION['messageError'] = $errorMessage;
        header('Location: ../signUp.php');
        exit;
    }

    // Sanificazione input
    $email = htmlspecialchars(strip_tags(trim($_POST['email'] ?? '')));
    $password = trim($_POST['password'] ?? '');

    if (empty($email) || !filter_var($email, FILTER_VALIDATE_EMAIL)) {
        redirectToSignupWithError("Invalid email format.");
    }

    if (strlen($password) < 8) {
        redirectToSignupWithError("Password must be at least 8 characters long.");
    }

    $conn = new mysqli("localhost", "root", "tua_password", "corso41");

    if ($conn->connect_error) {
        redirectToSignupWithError("Database connection failed.");
    }

    // Hash password
    $hashedPassword = password_hash($password, PASSWORD_DEFAULT);

    // Prepared statement
    $stmt = $conn->prepare("INSERT INTO logData (email, password) VALUES (?, ?)");
    $stmt->bind_param("ss", $email, $hashedPassword);

    if ($stmt->execute()) {
        header('Location: ../login.php');
        exit();
    } else {
        redirectToSignupWithError("Registration failed: " . $stmt->error);
    }

    $stmt->close();
    $conn->close();
}