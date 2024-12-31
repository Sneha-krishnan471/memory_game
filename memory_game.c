
Code:
HTML

html
Copy code
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Memory Game</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class="memory-game">
        <div class="card" data-framework="a"></div>
        <div class="card" data-framework="b"></div>
        <div class="card" data-framework="a"></div>
        <div class="card" data-framework="b"></div>
    </div>
    <script src="script.js"></script>
</body>
</html>
CSS

css
Copy code
.memory-game {
    display: flex;
    gap: 10px;
}

.card {
    width: 100px;
    height: 100px;
    background: #333;
    color: white;
    display: flex;
    justify-content: center;
    align-items: center;
    cursor: pointer;
}
.card.matched {
    background: green;
}
JavaScript

javascript
Copy code
const cards = document.querySelectorAll('.card');
let hasFlippedCard = false;
let firstCard, secondCard;

cards.forEach(card => card.addEventListener('click', flipCard));

function flipCard() {
    this.classList.add('flip');
    if (!hasFlippedCard) {
        hasFlippedCard = true;
        firstCard = this;
        return;
    }
    secondCard = this;
    checkForMatch();
}

function checkForMatch() {
    if (firstCard.dataset.framework === secondCard.dataset.framework) {
        firstCard.classList.add('matched');
        secondCard.classList.add('matched');
    } else {
        setTimeout(() => {
            firstCard.classList.remove('flip');
            secondCard.classList.remove('flip');
        }, 1000);
    }
    hasFlippedCard = false;
}