-- Keep a log of any SQL queries you execute as you solve the mystery.
-- 1. Consultando o crime ocorrido em Humphrey Street no dia 28/07/2021
SELECT description
  FROM crime_scene_reports
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND street = 'Humphrey Street';

-- 2. Procurando entrevistas feitas no mesmo dia
SELECT name, transcript
  FROM interviews
 WHERE year = 2021
   AND month = 7
   AND day = 28;

-- 3. Encontrar testemunhas que mencionam "bakery" nas entrevistas
SELECT name, transcript
  FROM interviews
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND transcript LIKE '%bakery%'
 ORDER BY name;
-- (Resultado: Eugene, Raymond, Ruth)

-- 4. Investigando as transações no caixa eletrônico da Leggett Street
SELECT p.name, atm.amount
  FROM atm_transactions atm
  JOIN bank_accounts ba ON atm.account_number = ba.account_number
  JOIN people p ON ba.person_id = p.id
 WHERE atm.year = 2021
   AND atm.month = 7
   AND atm.day = 28
   AND atm.atm_location = 'Leggett Street'
   AND atm.transaction_type = 'withdraw';

-- 5. Procurando o aeroporto de Fiftyville (para voos do ladrão)
SELECT id, abbreviation, full_name, city
  FROM airports
 WHERE city = 'Fiftyville';

-- 6. Listando voos de 29/07/2021 a partir de Fiftyville, ordenados pelo horário
SELECT flights.id, destination_airport.city AS destination_city, flights.hour, flights.minute
  FROM flights
  JOIN airports origin_airport ON flights.origin_airport_id = origin_airport.id
  JOIN airports destination_airport ON flights.destination_airport_id = destination_airport.id
 WHERE flights.year = 2021
   AND flights.month = 7
   AND flights.day = 29
   AND origin_airport.city = 'Fiftyville'
 ORDER BY flights.hour, flights.minute;
-- (Primeiro voo: 8:20 para Nova York, Flight ID = 36)

-- 7. Listar passageiros do primeiro voo
SELECT p.name, p.passport_number, passengers.seat
  FROM passengers
  JOIN people p ON passengers.passport_number = p.passport_number
 WHERE passengers.flight_id = 36
 ORDER BY p.passport_number;

-- 8. Analisando ligações telefônicas no dia do crime (28/07/2021) com duração <= 1 minuto
SELECT caller.name AS caller_name, receiver.name AS receiver_name, phone_calls.duration
  FROM phone_calls
  JOIN people caller ON phone_calls.caller = caller.phone_number
  JOIN people receiver ON phone_calls.receiver = receiver.phone_number
 WHERE phone_calls.year = 2021
   AND phone_calls.month = 7
   AND phone_calls.day = 28
   AND phone_calls.duration <= 60
 ORDER BY phone_calls.duration;
-- (Assim você já vê quem ligou pra quem em ligações rápidas)

-- 9. Investigando carros que saíram do estacionamento entre 10:15 e 10:25
SELECT p.name, bsl.license_plate, bsl.hour, bsl.minute
  FROM bakery_security_logs bsl
  JOIN people p ON bsl.license_plate = p.license_plate
 WHERE bsl.year = 2021
   AND bsl.month = 7
   AND bsl.day = 28
   AND bsl.activity = 'exit'
   AND bsl.hour = 10
   AND bsl.minute BETWEEN 15 AND 25
 ORDER BY bsl.minute;


