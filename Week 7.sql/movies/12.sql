SELECT movies.title
FROM movies
JOIN stars AS stars_cooper ON stars_cooper.movie_id = movies.id
JOIN stars AS stars_lawrence ON stars_lawrence.movie_id = movies.id
WHERE stars_cooper.person_id = (SELECT id FROM people WHERE name = 'Bradley Cooper')
  AND stars_lawrence.person_id = (SELECT id FROM people WHERE name = 'Jennifer Lawrence');
