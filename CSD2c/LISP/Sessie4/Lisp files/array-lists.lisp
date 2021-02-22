;;;; ***********************************************
;;;; HISTORY: started 090316
;;;; functions with array's and lists (+ the use of assoc)
;;;; Author: michel.koenders@hku.nl
;;;; ***********************************************
;;;; 120316 mk, created second version of file.
;;;; 100217 mk, small tweeks.
;;;; 240217 mk, tweeks on format.
;;;; 030317 mk, tweeks.
;;;; 110219 mk, tweeks on text.
;;;; 060320 mk, tweeks.




;; ----------------- functions ---------------------------
(defun copylist-to-array-func (arg1-list)
  "copylist-to-array-func - documentation string"
  (let ((data-array (make-array '(10) :initial-element 0.0))     ;; bind 3 local variables. create an empty array with the initial element 0.0
        (data-list (make-list '10))                              ;; create a list.
        (length-of-arg1-list (length arg1-list)))                ;; length of the list.
    (dotimes (i length-of-arg1-list)                             ;; dotimes i is used for iterating an array until it reaches length of array.
      (setf (aref data-array i) (nth i arg1-list)                ;; store data in arrays with setf: array-name index-number.
            (nth i data-list) (nth i arg1-list)))                ;; lists: index-number list-name.
    (format t "~%arg1-list = ~A ~%data-array = ~A ~%data-list = ~A ~%" arg1-list data-array data-list)))   ;; NB "~%" = (terpri)



(defun copylist-to-2dim-array-func (arg1-list)
  "CopyList-to-2DimArray-function - documentation string"        ;; use let*we need the value (binding) of length-of-arg1-list.
  (let* ((length-of-arg1-list (length arg1-list))                ;; length of the list.
         (data-array (make-array '(30 2) :initial-element 0.0))  ;; creates a 2 dimensional array with 30 cells with an initial-element of 0.0.
         (data-list  (make-list length-of-arg1-list :initial-element 0.0))) ;; creates a list of length of the list (length arg1-list).
    (dotimes (i length-of-arg1-list)                             ;; dotimes i iterates a list until it reaches length of arg1-list.
      (setf (aref data-array i 0) (nth i arg1-list)                    ;; setf array cel dimension: 0 with nth 0 element from the arg1-list.
            (aref data-array i 1) (+ (nth i arg1-list) (random 1.0))   ;; setf array cel dimension: 1
            (nth i data-list) (list (nth i arg1-list) (+ (nth i arg1-list) (random 1.0))))) ;; setf (return) data-list: (list arg1 arg2*random)
    (format t "~%arg1-list = ~A ~%data-array = ~A ~%data-list = ~A ~%" arg1-list data-array data-list)))   ;; NB "~%" = (terpri)



(defun destructive-copy-with-push-and-pop-func-1 (arg1-list)
  "destructive-copy-with-push-and-pop-func-1 - This is a destructive way to copy a list."
  (let ((data-list '()))
    (dotimes (i (length arg1-list))
      (setf data-list (push (pop arg1-list) data-list)))
    (format t "~%arg1-list = ~A  ~%data-list = ~A ~%" arg1-list data-list)))   ;; NB "~%" = (terpri)

(defun destructive-copy-with-push-and-pop-func-2 (arg1-list)
  "destructive-copy-with-push-and-pop-func-2 - This is a destructive way to copy a list."
  (let ((data-list '()))
    (dolist (i arg1-list)
      (setf data-list (push (pop arg1-list) data-list)))
    (format t "~%arg1-list = ~A  ~%data-list = ~A ~%" arg1-list data-list)))

(defun destructive-copy-with-push-and-pop-func-3 (arg1-list)
  "destructive-copy-with-push-and-pop-func-3 - This is a destructive way to copy a list."
  (let ((data-list '()))
    (dolist (i arg1-list)
      (setf data-list (push i data-list)))
    (format t "~%arg1-list = ~A  ~%data-list = ~A ~%" arg1-list data-list)))




(defun copy-with-copy-list-func (arg1-list arg2-array)
  "copy-with-copy-list-func - documentation string"
  (let ((copy-of-a-list '())
        (copy-of-an-array))
    (setf copy-of-a-list (copy-list arg1-list)                   ;; Returns a new list EQUAL but not EQ to arg1-list.
          copy-of-an-array (copy-tree arg2-array))               ;; copy-tree prints any seq. tree. NB copy-alist voor association lists!!!

    (format t "~%arg1-list = ~A" arg1-list)                      ;; NB "~%" = (terpri)
    (format t "~%copy-of-a-list = ~A ~%" copy-of-a-list)
                                                                 ;; if member found in list: print found member + the rest (cdr) of the list.
    (format t "~%copy-of-a-list-with-the-use-of-member '7 = ~A ~%" (member '7 copy-of-a-list)) 

    (format t "~%arg2-array = ~A ~%" arg2-array)
    (format t "~%copy-of-an-array = ~A ~%" copy-of-an-array)))




;;;;----------------------------------------------------------
;;;;---------------Association lists with predicates----------
;;;;----------------------------------------------------------

(defun return-an-associated-list (arg1-list any-item)
  "return-an-associated-list documentation string"
  (assoc any-item arg1-list))



;; global scope variable with association list with arguments (chord-names) - for use with assoc.
(defvar *MyChords* '((Cmaj '(c e g))    ;;; (0 4 7)   (c (2) d (2) e (1) f (2) g (2) a (2) b (1) c) midi distances: (0 - 2 - 4 - 5 - 7 - 9 - 11 - 12)
                     (Cmin '(c es g))   ;;; (0 3 7)
                     (Emaj '(e gis b))  ;;; (0 4 7)
                     (Emin '(e g b))    ;;; (0 3 7)
                     (Fmaj '(f a c))    ;;; (0 4 7)
                     (Fmin '(f as c))   ;;; (0 3 7) ;; etc.... Add more chords..
                     ))


(defun chord-assoc (chord-name)
  "chord-assoc documentation string"
  (let ((all (assoc chord-name *MyChords*))                           ;; association list: first arg - any Lips function (our cae: chord-names), second arg - Alist
        (name-of-chord (first (assoc chord-name *MyChords*)))           ;; returns first member of list.
        (chord-key-numbers (second (assoc chord-name *MyChords*))))   ;; returns second member of list. 
  (format t "~%~A" all)
  (format t "~%~A" chord-name)
  (format t "~%~A" name-of-chord)
  (format t "~%~A" chord-key-numbers)))



(defun chord-informer (chord-name)
  "chord-informer documentation string"
  (let ((chord-name2 (first (assoc chord-name *MyChords*)))
        (chord-key-numbers (second (second (assoc chord-name *MyChords*)))))  ;; returns the second from the second list....
  (format t "~%~A" chord-name2)                                  ;; so we can print the clean names...
  (format t "~%~A" chord-key-numbers)))
    



(defun note-name-to-midi (note-name)
  "translates note-name to midi number. Names according Theo Willemze Algemene Muziekleer pg.99"
  (if (not (eq note-name nil))
      (case note-name
        (c 0)  (bis 0)                        (deses 0) ;; NB: MIDI: deses equals c equals bis (enharmonic).
               (cis 1)              (des 1)
        (d 2)           (cisis 2)             (eses 2)
               (dis 3)              (es 3)
        (e 4)           (disis 4)   (fes 4)
        (f 5)  (eis 5)                        (geses 5)
               (fis 6)              (ges 6)
        (g 7)           (fisis 7)             (ases 7)
               (gis 8)              (as 8)
        (a 9)           (gisis 9)             (beses 9)
               (ais 10)             (bes 10)
        (b 11)          (aisis 11)  (ces 11)
        (otherwise 
         (format t "~%ERROR: unknown note name~%")))))


(defun midi-key-number-to-note-name (midi-key)
  "translates midi-key-numbers to-note-names."
  (let ((return-list-of-note-names '()))
    (if (not (eq midi-key nil))
        (case (mod midi-key 12)
          (0 'c)     ;; NB don't forget to use a quote. Otherwise the symbol will be evaluated as a variable.
          (1 'des/cis)
          (2 'd)
          (3 'es/dis)
          (4 'e)
          (5 'f)
          (6 'ges/fis)
          (7 'g)
          (8 'as/gis)
          (9 'a)
          (10 'bes/ais)
          (11 'b)
          (otherwise (format t "~%ERROR: unknown note number???~%")))
      )))




(defun octaver (octave-number &optional (oct-nump nil) (oct-namep nil) (oct-name-short1p nil) (oct-name-short2p nil) (oct-valuep nil))
  "translates octave-number to correct octave. All names according Theo Willemze Algemene Muziekleer pg.101"
  (let ((octave-alist '())
        (return-list '()))
    (setf octave-alist '((0  'sub-contra-octave   "''C"       "2C"   0)   ;; list of all pitch-classes
                         (1  'contra-octave       "'C"        "1C"  12)
                         (2  'great-octave        "C"         "C"   24)
                         (3  'small-octave        "c"         "c"   36)
                         (4  '1-line-octave       "c'"        "c1"  48)
                         (5  '2-line-octave       "c''"       "c2"  60)
                         (6  '3-line-octave       "c'''"      "c3"  72)
                         (7  '4-line-octave       "c''''"     "c4"  84)
                         (8  '5-line-octave       "c'''''"    "c5"  96)
                         (9  '6-line-octave       "c'''''''"  "c6" 108)    ;; normaly the story ends with c6 (MIDI: 120).....
                         (10 '7-line-octave       "c''''''''" "c7" 120)))  ;; but MIDI range is bigger (just a few notes). g7 = MIDI value 127 !

    (if oct-nump     ;; check all arguments of the function.
        (setf return-list (cons (nth 0 (assoc octave-number octave-alist)) return-list)))
    (if oct-namep
        (setf return-list (cons (nth 1 (assoc octave-number octave-alist)) return-list)))
    (if oct-name-short1p
        (setf return-list (cons (nth 2 (assoc octave-number octave-alist)) return-list)))
    (if oct-name-short2p
        (setf return-list (cons (nth 3 (assoc octave-number octave-alist)) return-list)))
    (if oct-valuep
        (setf return-list (cons (nth 4 (assoc octave-number octave-alist)) return-list)))
  
    (reverse return-list)))




(defun chord-inversion (chord-name inversion-number &optional (octave 0))
  "chord-inversion2 documentation string"
  (let* ((chord-key-names (second (second (assoc chord-name *MyChords*))))
         (return-inverted-chord (make-list (length chord-key-names)))
         (note-midi-values '()) ;; extra list.
         (j 0)                  ;; we need a counter
         (set-octave 0))
  ;;  (print chord-key-names)
  ;;  (print octave)
    (dolist (i chord-key-names)
      (progn
        (cond ((and (eq j 0) (eq inversion-number 1)) (setf set-octave 12))  ;; just for transposing if note 
              ((and (eq j 0) (eq inversion-number 2)) (setf set-octave 12))
              ((and (eq j 1) (eq inversion-number 2)) (setf set-octave 12))
              (t
               (setf set-octave 0)))
        (setf (nth (mod (+ inversion-number inversion-number j) 3) return-inverted-chord) (+ set-octave
                                                                                             (note-name-to-midi i)
                                                                                             (first (Octaver octave nil nil nil nil t))))
        (incf j))) ;; j++   add one to our counter.

    (dolist (i chord-key-names)
      (setf note-midi-values (cons (+ (note-name-to-midi i) 
                                      (* octave 12)) note-midi-values)))    ;; translate note-name to MIDI note number + (Octave * 12).
    (format t "~%Original chord: ~A" chord-key-names)
    (format t "~%Original chord octave transposition: ~D and name: ~A" octave (second (first (Octaver octave nil t nil nil nil))))
    (format t "~%Original chord MIDI values: ~A" (reverse note-midi-values))

    ;;; don't forget to set list to nil !!!
    (setf note-midi-values '())

    (dolist (i return-inverted-chord)
      (setf note-midi-values (cons (midi-key-number-to-note-name i) note-midi-values)))  ;; translate MIDI note number to note name.
    (format t "~%Inversion: ~A" inversion-number)
    (format t "~%Inverted chord note names: ~A" (reverse note-midi-values))     
    (format t "~%Inverted chord MIDI key values: ~A" return-inverted-chord)))




;; ----------------top-function----------------------------
;; (toplevel-function-arr+list)
(defun toplevel-function-arr+list ()
  "toplevel-function-arr+list(), documentation string"

  ;;;-------------------------

  (copylist-to-array-func '(1 2 3 4 5 6 7 8 9 10))

  ;;;-------------------------

  (copylist-to-2dim-array-func '(1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20))

  ;;;-------------------------

  (destructive-copy-with-push-and-pop-func-1 '(1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20))
  (destructive-copy-with-push-and-pop-func-2 '(1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20))
  (destructive-copy-with-push-and-pop-func-3 '(1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20))

  ;;;-------------------------

  (copy-with-copy-list-func '(1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20) #2A((1 1.019587) (2 2.4702788) (3 3.6150577) (4 4.087021) (5 5.353077) (6 6.4311757) (7 7.5191527) (8 8.446845) (9 9.453364) (10 10.617077) (11 11.503009) (12 12.218132) (13 13.347851) (14 14.99013) (15 15.598208) (16 16.216074) (17 17.497746) (18 18.633864) (19 19.284119) (20 20.6303) (0.0 0.0) (0.0 0.0) (0.0 0.0) (0.0 0.0) (0.0 0.0) (0.0 0.0) (0.0 0.0) (0.0 0.0) (0.0 0.0) (0.0 0.0)))

  (return-an-associated-list '((1 1.019587) (2 2.4702788) (3 3.6150577) (4 4.087021) (5 5.353077) (6 6.4311757) (7 7.5191527) (8 8.446845) (9 9.453364) (10 10.617077) (11 11.503009) (12 12.218132) (13 13.347851) (14 14.99013) (15 15.598208) (16 16.216074) (17 17.497746) (18 18.633864) (19 19.284119) (20 20.6303) (0.0 0.0) (0.0 0.0) (0.0 0.0) (0.0 0.0) (0.0 0.0) (0.0 0.0) (0.0 0.0) (0.0 0.0) (0.0 0.0) (0.0 0.0)) '11) ;; gives us the assoc '11 of the list.


  ;;;-------------------------
  (chord-assoc 'Cmaj)
  (chord-informer 'Cmaj)
  (terpri)
  (chord-inversion 'Cmaj 1 0) ;; arguments: chord-name, inversion (omkering) and octave-transposition.
  (terpri)
  (chord-inversion 'Cmaj 2 6)
  (terpri)

  (chord-inversion 'Emaj 1 4)
  (terpri)
  (chord-inversion 'Emin 2 7)

  (terpri)
  (chord-inversion 'Fmaj 1 4)
  (terpri)
  (chord-inversion 'Fmin 2 7)

  ) ;; returns nil



;;; ****************************

