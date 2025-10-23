# Devlop_ment:
[devolopment](https://www.notion.so/C-p-Tracking-265fafbe3c2f8005b2b2ebe0843c3231?source=copy_link)
<details>
    <summary>INTRODUCTION TO DEVops</summary>


DevOps is a culture and set of practices that integrates **development (Dev)** and **operations (Ops)** to improve collaboration, automation, and continuous delivery.

**DevOps Lifecycle:**

**Plan → Develop → Build → Test → Release → Deploy → Operate → Monitor**

## 

## Version Control with Git

- **What is Git?**
    
    A **distributed version control system** that tracks code changes and enables collaboration.
    
- **Key Commands:**
    - `git clone` → Clone repository
    - `git commit` → Save changes
    - `git push` → Send changes to remote repo
    - `git pull` → Get updates from remote repo
    - `git branch` → Work on multiple versions
- **Collaboration with GitHub:**
    - Pull Requests (PRs)
    - Issue tracking
    - Team workflows
- **Hands-on Exercise:**
    
    Practice Git basics: branching, making changes, staging, committing, pushing, merging, and deleting branches.
    

---

## 3. 🔹 Basics of CI/CD

- **Definition:**
    - **CI (Continuous Integration):** Automates integration of code changes into shared repo.
    - **CD (Continuous Delivery/Deployment):** Automates release and deployment to production.
- **Tools:**
    - Jenkins
    - GitHub Actions
    - GitLab CI/CD
- **Benefits:**
    - Faster testing & deployment cycles
    - Reduced human errors
- **YAML Basics:**
    - Human-readable configuration language
    - Used for pipelines & workflows
    - Syntax includes key-value pairs, lists, and indentation for nesting
- **GitHub Actions with YAML:**
    - Workflows defined in `.github/workflows/`
    - Workflows specify events (push, pull request) and jobs (build, test, deploy)
- **Hands-on Exercise:**
    
    Create a GitHub Actions pipeline for automating a simple build process.
    

## 

## 4. Introduction to Containers

- **What are Containers?**
    
    Lightweight, isolated environments for running applications consistently.
    
- **Docker Basics:**
    - **Images** → Templates for containers
    - **Containers** → Running instances of images
    - **Dockerfile** → Script to build images
- **Benefits:**
    - Portability (runs anywhere)
    - Scalability
    - Consistent environments
    - Resource efficiency
    - Faster deployments
- **Basic Docker Commands:**
    - `docker build` → Build image
    - `docker run` → Start container
    - `docker stop` → Stop container
    - `docker ps` → List running containers

## 5. Configuration Management Basics

- **Definition:**
    
    Automating system setup, configuration, and maintenance.
    
- **Ansible:**
    - Uses YAML-based playbooks
    - Workflow: Write playbook → Define inventory → Run playbook → Apply changes
- **Benefits:**
    - Ensures consistency
    - Efficiency and speed
    - Reduces human errors
    - Supports version control & collaboration
    - Faster recovery during failures

---

## 6. 🔹 Monitoring and Logging

- **Importance of Monitoring:**
    - Ensures uptime
    - Tracks performance
    - Detects issues early
- **Types of Monitoring:**
    - Infrastructure monitoring
    - Application monitoring
    - User experience monitoring
- **Tools:**
    - **Prometheus** → Metric collection
    - **Grafana** → Visualization & dashboards
- **Logging:**
    - Centralized logging with **ELK stack** (Elasticsearch, Logstash, Kibana)
- **Benefits of Logging:**
    - Root cause analysis
    - Auditing and compliance
    - Debugging and troubleshooting
</details>

<details>
    <summary>How Backend Works and How Data Is Stored Using a Data Management System</summary>
    
1. What Is the Backend

The backend is the server-side part of a software system that handles operations invisible to the user.
It is responsible for:

Managing and storing data

Executing business logic

Communicating with the frontend

When a user performs an action on the frontend (e.g., saving data or logging in), the backend processes that action and interacts with the database to return the correct result.

2. Backend Workflow (Step-by-Step)
Step 1: User Action (Frontend)

A user interacts with the frontend interface — for example, entering data and clicking a Save button.

Step 2: Request Sent (API)

The frontend sends a request to the backend through an API.

Example:

POST /api/notes
Content-Type: application/json

{
  "title": "Shopping List",
  "content": "Milk, Bread, Eggs"
}

Step 3: Backend Receives the Request

The backend (e.g., Node.js, Django, Flask) performs:

Input validation

Authentication checks

Business logic execution

Database operations via a Database Management System (DBMS)

Step 4: Data Management System (DBMS)

The DBMS handles data storage, retrieval, and management.

Common Types:

Relational Databases (SQL): MySQL, PostgreSQL, SQLite

Non-Relational Databases (NoSQL): MongoDB, Firebase, Cassandra

Step 5: Data Storage Examples

SQL (Relational) Example:

id	title	content
1	Shopping List	Milk, Bread, Eggs

NoSQL (Document-based) Example:

{
  "_id": "123",
  "title": "Shopping List",
  "content": "Milk, Bread, Eggs"
}

Step 6: Response to Frontend

Once the DBMS confirms the operation, the backend sends a response:

{
  "status": "success",
  "note_id": 123
}


The frontend then displays a success message or updated data to the user.

3. Backend Architecture Overview
[Frontend (User)] ⇄ [Backend Server] ⇄ [Database]

Component	Description
Frontend	User interface (React, Angular, Flutter)
Backend Server	API and business logic (Node.js, Django, Flask)
Database	Data management system (PostgreSQL, MongoDB)
4. Key Backend Concepts
Concept	Description
API	Interface that enables communication between frontend and backend
Server	Runs backend code and handles requests
DBMS	Manages data storage and retrieval
ORM (Object Relational Mapper)	Simplifies database interaction (e.g., Mongoose, Prisma, SQLAlchemy)
Authentication	Controls access and ensures security
Caching	Temporarily stores data to improve performance
5. Example Tech Stack
Layer	Example Technologies
Frontend	React, Vue.js, Flutter
Backend	Node.js (Express), Django, Flask
Database	MongoDB, PostgreSQL, MySQL
Hosting	AWS, Render, Vercel, Firebase
6. Data Flow Summary

User triggers an action in the frontend.

The frontend sends a request to the backend via API.

The backend validates and processes the request.

The backend interacts with the database (DBMS).

The DBMS stores or retrieves data as required.

The backend sends the processed data back to the frontend.

The frontend updates the UI accordingly.
</details>


