import React, { useState } from 'react';
import './App.css'
// Define movie data
const movies = {
  action: ["The Dark Knight", "Tiger 3", "Jawan", "Gladiator"],
  comedy: ["Bhagam Bhag", "Superbad", "Chup Chup ke", "Bridesmaids"],
  drama: ["The Shawshank Redemption", "Forrest Gump", "Hera Pheri", "The Godfather"],
  horror: ["The Shining", "Kanchana", "Hereditary", "A Quiet Place"]
}
const books = {
  love : ["Pride and Prejudicw", "Love speaks", "Outlander", "Magnetic Love"],
  motivational: ["Big magic", "The Alchemist", "Think and grow rich", "Atomic habits"],
  drama: ["Hamlet", "Romeo and juliet", "Macbeth","The Tempest"],
  horror: ["Frankesntein", "Kanchana", "Beloved", "Dracula"]
};
// Movie component
const Movie = ({ title }) => {
  return <li>{title}</li>;
  }
 
const Book = ({ title }) => {
  return <li>{title}</li>;
  }

// MovieList component
const MovieList = ({ movies }) => {
  return (
    <ul>
      {movies.map((movie, index) => (
        <Movie key={index} title={movie} />
      ))}
    </ul>
  );
};
//booklist component
const BookList = ({ books }) => {
  return (
    <ul>
      {books.map((book, index) => (
        <Book key={index} title={book} />
      ))}
    </ul>
  );
};

// App component
const App = () => {
  const [genre, setGenre] = useState('action');
    const [type, setType] = useState('love');
  

  return (
    <div class="d1" style={{
      width: '1200px',
    height: '600px',
    backgroundSize:'cover',
    backgroundImage :'url("https://wallpaperaccess.com/full/656317.jpg")'
    }}>
        <div class="d2">
      <h1 class="he"><marquee class="m1"><u> Movie Recommendations</u></marquee></h1>
      <select value={genre} onChange={(e) => setGenre(e.target.value)}>
        <option value="action">Action</option>
        <option value="comedy">Comedy</option>
        <option value="drama">Drama</option>
        <option value="horror">Horror</option>
      </select>
      <MovieList movies={movies[genre]} /></div>
      <div class="d3">
        <h1 class="hw"><marquee class="m2"><u>Books Recommendation</u></marquee></h1>
        <select value={type} onChange={(e) => setType(e.target.value)}>
        <option value="love">Love</option>
        <option value="motivational">Motivational</option>
        <option value="drama">Drama</option>
        <option value="horror">Horror</option>

        </select>
        <BookList books={books[type]}/>
        </div>
            </div>


  );
};

export default App;
