> [!note] Classification ML
> - Predicts a discrete category or class
> - Used for filtering spam(is/is not spam)

> [!note] Regression ML
> - Predicts a continuous numeric value, such as weather or housing prices

> [!note] Clustering ML
> - Used when you don't know what's happening or why
> - e.g. Why are there lots of students leaving BCIT?
> - Will be used to identify what parameters are useful

# ML Methodologies
- Data Pre-processing
	- Collection and preparation
- Feature Engineering and Selection
	- Transform the raw data into features the algorithm can understand and use to learn
- Model selection and Architecture
	- Choose the ML algorithm, or design one
- Training and Validation
	- Use the prepared data to train the model
	- Check its performance
	- Split the data into Training and Validation
- Deployment and Integration
	- Integrate the model into a system or program to perform its intended task
- Monitoring and Maintenance
	- Keep an eye on the performance and update it as needed
# Issues
- Overfitting
	- ML gives accurate predictions for training data, but not for new data
- Underfitting
	- Model is unable to capture the relationship between input and output variables
# Parametric and Non-Parametric Model
- Parametric Methods
	- Mode summarizes data with a set of parameters of fixed sized
	- No many how much data you give to the model, it doesn't change how many parameters it needs
	- e.g. Linear Regression, Naive Bayes
- Non-Parametric Mode
	- Refer back to data to make predictions
	- Good when you have a lot of data, but no prior knowledge about the data
	- E.G. KNN
## Parameter examples
- Naive Bayes
	- Class Priors: 
		- Probability of each class
	- Likelihoods
		- Probability of a feature occurring, given a class
	- Smoothing
		- Like Laplace smoothing.
		- Used to prevent zeros(set $\alpha=1$.
# Naive Bayes
- Simple
- Estimates if a new "item" belongs to a class
	- Decides "What class has a higher probability"
- Assumes **every feature value is independent**
- High accuracy, especially if Normally Distributed
- Parametric Model - Can be linear or non-linear, depending on implementation
- Linear - Standard implementation leads to linear decision boundary
- Gaussian Naive Bayes:
	- Assumes features are normally distributed
	- Assumes the parameters are mean($\mu$) and standard deviation($\sigma$) within each class
- Multinomial Naive Bayes:
	- Used for discrete counts, like word counts in a text
- Bernoulli Naive Bayes:
	- For binary features - absence/presence of a word
# Infer.Net
- ML Platform
- Specializes in running Bayesian Inference
- [Tutorials](https://dotnet.github.io/infer/userguide/Infer.NET%20tutorials%20and%20examples.html)
## Bayes Point Machine
- Employs Bayesian Inference; involves updating probability estimates when new evidences gets added
# Regression
- Statistical method for modeling the relationship between a **dependent** variable and one-or-more **independent** variables
	- The goal is the predict how changes in the independent variables affect the dependent variable
- Parameters for Regression Model are *usually* estimated using "Method of Least Squares"
- Can be done in R, spreadsheets, and some calculators
- Other methods:
	- Bayesian Linear Regression
		- Extends linear regression by treating the regression coefficients as probability distributions
	- Nonparametric Regression
	- Interval Predictor Model
- 
