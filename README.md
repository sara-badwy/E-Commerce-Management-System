# E-Commerce-Management-System

A comprehensive C++ console-based e-commerce application that provides a complete online shopping experience with separate interfaces for customers and administrators. This system features robust user authentication, product management, shopping cart functionality, and order processing, all built with object-oriented programming principles and efficient memory management.

## Key Features

**For Customers:**
- User registration and secure login system
- Product browsing and search functionality
- Interactive shopping cart management
- Seamless checkout process with order confirmation
- Order history tracking

**For Administrators:**
- Complete product lifecycle management (add, edit, delete)
- Real-time inventory control (price and quantity updates)
- Product search and catalog management
- Admin account management

## Technical Highlights

- **Object-Oriented Architecture**: Clean separation of concerns with dedicated classes for Users, Products, Orders, and system management
- **Memory Management**: Proper resource handling with destructors and smart pointer-like patterns
- **Efficient Data Structures**: Utilizes unordered_map for O(1) lookups and optimal performance
- **Input Validation**: Comprehensive error handling for user inputs and edge cases
- **Unique ID Generation**: Automated ID creation for users, products, and orders

## Project Structure

The system is organized into modular classes including `ECommerceSystem` (main controller), `User` (base class), `Customer` and `Admin` (derived classes), `Product`, `Order`, and `Utility` (helper functions). This modular design ensures maintainability and scalability while providing a solid foundation for future enhancements like database integration, GUI implementation, or web service adaptation.

Perfect for educational purposes demonstrating C++ best practices, design patterns, and complete system development lifecycle implementation.
