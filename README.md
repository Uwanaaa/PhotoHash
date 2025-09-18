# 📷 Image dHash Generator (Node.js + OpenCV)

This project provides a native Node.js module that computes the [dHash (difference hash)](https://www.hackerfactor.com/blog/index.php?/archives/529-Kind-of-Like-That.html) of an image using OpenCV.
dHash is a perceptual hashing algorithm that generates a compact fingerprint of an image based on its brightness structure — ideal for detecting duplicates or near-identical images.

---

## 🚀 Features

- Converts input image to grayscale
- Resizes image to 9×8 for horizontal pixel comparison
- Generates a 64-bit binary hash based on brightness differences
- Fast and lightweight implementation using C++ and OpenCV
- Exposed to Node.js via N-API

---

## 📦 Installation

```bash
npm install

```

## 🧠 Why dHash?

Unlike cryptographic hashes, **dHash** is designed to produce similar outputs for visually similar images. It’s perfect for:

- Duplicate detection  
- Reverse image search  
- Image clustering  
- Content moderation  

---

## 📋 License

**MIT License** — feel free to use, modify, and contribute!

---

## 🙌 Contributing

Pull requests are welcome! If you have ideas for performance improvements — such as:

- Bitwise hashing  
- Threading  
- GPU acceleration  

Feel free to open an issue or submit a PR.

---

