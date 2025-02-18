# Smart Agri-tech

Smart Farming Assistant
Overview
Smart Farming Assistant is an innovative solution that leverages advanced technology to help farmers enhance productivity and make informed decisions. The platform features a Smart Crop Recommendation system powered by machine learning, suggesting optimal crops based on soil nutrients, climate, and historical data. Additionally, it includes a Plant Disease Identification tool using Convolutional Neural Networks (CNNs) to diagnose plant diseases from images, enabling timely interventions.

Other key features include real-time Weather Forecasts, tailored Fertilizer Recommendations based on soil quality and crop requirements, and a Smart Farming Guide for efficient crop management. With a user-friendly web application, farmers can easily access these insights to optimize their farming practices.

Research Paper
This project is based on the research paper published on IEEE: IEEE: Smart Crop Recommendation System with Plant Disease Identification View Paper

Features
Smart Crop Recommendation: Utilizes machine learning to suggest the best crops based on soil nutrients, climate, and historical data.

Plant Disease Identification: Uses CNNs to detect and classify plant diseases from images, ensuring timely interventions.

Fertilizer Recommendation: Provides customized fertilizer suggestions based on soil quality and crop needs.

Today's Weather Forecast: Delivers real-time weather updates, including temperature and humidity, to assist in farm planning.

Smart Farming Guide: Offers advice on planting schedules and crop management strategies to maximize productivity.

User-Friendly Interface: An intuitive platform for easy data input and personalized recommendations.

Crop Recommendation Model
The Crop Recommendation Model employs machine learning algorithms to suggest the best crops based on environmental and soil factors. It analyzes soil nutrients, temperature, humidity, pH, and rainfall to provide tailored recommendations. Among seven classification algorithms tested, Random Forest achieved the highest accuracy of 99.55%, ensuring reliable crop selection.

Dataset
Rows: 2200

Columns: 8 (Nitrogen, Phosphorous, Potassium, Temperature, Humidity, pH, Rainfall, and Crop Label)

Goal: Predict the best crop based on soil and environmental conditions.

Model Architecture
Seven classification algorithms were tested for crop recommendation:

Decision Tree

Gaussian Naive Bayes

Support Vector Machine (SVM)

Logistic Regression

Random Forest (Best accuracy: 99.55%)

XGBoost

KNN

Integration
This system integrates Crop Recommendation and Plant Disease Identification models to provide farmers with comprehensive support. The combination of these models helps optimize crop selection and manage plant diseases effectively, improving sustainability and productivity.

System Architecture
For a visual overview, refer to the diagram below: 📌 System Architecture

Results
Random Forest achieved 99.55% accuracy, making it the most reliable model.

Accuracy comparison of different models:

Algorithm	Accuracy (%)
Decision Tree	90.00
Gaussian Naive Bayes	99.09
Support Vector Machine (SVM)	10.68
Logistic Regression	95.23
Random Forest	99.55
XGBoost	99.09
KNN	97.50
📌 Accuracy vs Crop Graphs visualize performance comparisons.

Plant Disease Identification Model
The Plant Disease Identification Model uses CNNs to detect plant diseases from leaf images. It is trained on the Plant Disease Image Dataset, consisting of 70,295 training images and 17,572 validation images, covering 38 disease classes across 14 crops. It accurately identifies diseases such as Apple Scab, Tomato Blight, and Powdery Mildew, assisting farmers in early detection.

Dataset
Training Images: 70,295

Validation Images: 17,572

Disease Classes: 38 across 14 crops

Image Size: Standardized to 128x128 pixels

Model Architecture
CNN-based Deep Learning Model trained for disease detection.

Helps farmers diagnose diseases early and take corrective measures.

Key Features
Crop-Specific: Identifies diseases for a set of 14 crops.

Disease Diagnosis: Classifies plant diseases based on leaf images.

High Accuracy: Provides precise detection for early intervention.

Future Enhancements
Integration with Social Media (LinkedIn, GitHub) for detailed user profiling.

More advanced NLP-based Personalized Career Counseling.

Real-time job market analysis for emerging career trends.

Gamification elements to enhance user engagement.

Expansion of crop recommendations based on regional data.
