# 🧑‍💼 Job Portal System in C++

This is a simple **console-based Job Portal Management System** written in C++. It allows **Admins** to manage job listings and **Users** to register, login, and apply for jobs.

---

## 📋 Features

### Admin
- Login with a password (`pass@123`)
- Add new jobs (title + description)
- Remove existing jobs
- View all listed jobs
- View all pending job applications
- Review and update application status (Accept/Reject)

### User
- Register a new account
- Login with credentials
- View all available jobs
- Apply for jobs
- Check status of applications

---

## 🛠️ Structure

### Data Structures Used
- `struct Job` – holds job ID, title, and description
- `struct Application` – holds job ID, applicant username, and application status
- `struct User` – holds username and password

### Constants
- `MAX_JOBS` – maximum jobs allowed: 100
- `MAX_APPLICATIONS` – maximum applications allowed: 100
- `MAX_USERS` – maximum users allowed: 100
- `ADMIN_PASSWORD` – admin login password: `"pass@123"`

---


