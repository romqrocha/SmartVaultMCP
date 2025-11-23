# Fundamentals of AI
- AI refers to all systems that are intended to mimic human intelligence
- ML is a subset
- Deep Learning is meant to recognize complex patterns.
	- Intended to mimic how the human brain processes information
# Machine Learning
>[!note] Machine Learning
>Algorithms used to create models that improve over time by 'learning' from the data its fed
## Unsupervised Learning
- Groups and interprets data only using input data
- Uses unlabeled data
- Has no predefined categories or outcomes
## Supervised Learning
- Uses labeled data
- Can use Classification Techniques(Discrete Responses)
	- Decision Trees
	- Neural Networks
	- Naive Bayes
- Can use Regression Techniques(Continuous Responses; e.g. Weather changes, machine parameters)
# User Modeling
- A field of HCI, AI
- Probabilistic model
- Create representation of users to understand attributes(behaviors, goals, needs, etc.)
- Should include "interface agents" that can predict actions based on
	- Current state
	- Profile
	- Previous actions
	- Prior beliefs
- Difficult to model emotional needs due to difference in culture, socioeconomics, etc.
# Bayesian Models
## Theorem
- Uses "Conditional Probabilities"
	- Probabilities **IF** something happens
	  `P(H | X) = (likelihood * prior)/ normalized Constant`
## Bayesian Network
- Represented by a graph
	- Nodes are random variables
	- Should be [[Directed Acyclic Graph]]
# Stochastic System
- Stochastic means "Pertaining to Chance"
- Stochastic systems are **NON-Deterministic**
# Naive Bayes
- Simple supervised ML algorithm
- Uses Bayes Theorem
- Commonly used for text analysis
- "Naive" because it assumes each input variable are independent(e.g. each word is unrelated to the previous and following word)
- Good for classification
	- Can predict categories of item/data/case
	- Predicted variable(output) is called a class
	- Possible values of a class are called Labels
- Can be used for
	- Real-time and multi-class predictions
	- text classification
	- spam filtering
	- sentiment analysis