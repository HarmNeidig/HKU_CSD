;;;***********************************************************
;;; HISTORY: started 250216
;;; lisp: conditional testing with the use of if, cond and case.
;;; michel.koenders@hku.nl
;;; 270216 mk, some tweeks on the functions.
;;; 240217 mk, tweeks.
;;; 030317 mk, tweeks.




;; ----------------- functions ---------------------------
               
(defun test-type-with-one-condition-is-true (MyList)
  "function test-type-with-one-conditions-is-true (arg: list), returns a list. checks only for one type of predicate: if found exit condition."
  (let ((return-list '()))
    (dolist (i MyList)
      (progn
        (cond ((functionp i) (setf return-list (cons 'function-type return-list)))
              ((listp i)     (setf return-list (cons 'list-type return-list)))
              ;;      ((numberp i)           ;; if true pops out of the conditional test, no more checking for float etc.
              ;;       (setf return-list (cons 'number-type return-list)))
              ((integerp i)  (setf return-list (cons 'integer-type return-list)))
              ((floatp i)    (setf return-list (cons 'float-type return-list)))
              ((complexp i)  (setf return-list (cons 'complex-type return-list)))
              ((symbolp i)   (setf return-list (cons 'symbol-type return-list)))
              ((stringp i)   (setf return-list (cons 'string-type return-list)))
              (t                            ;; if all previous conditions have failed (non are t).
               (setf return-list (cons 'unknown-type return-list))))))     ;; if everything fails.
    (reverse return-list)))                                                ;; returns list in right order. 



(defun test-type-with-multiple-conditions-are-true (MyList)
  "function test-type-with-multiple-conditions-are-true (arg: list), returns a list. Checks for multiple predicates: e.g. if numberp & floatp or integerp."
  (let ((return-list '()))
    (dolist (i MyList)
      (progn
        (cond ((stringp i)  (setf return-list (cons 'string-type return-list))))   ;; check if string
        (cond ((symbolp i)  (setf return-list (cons 'symbol-type return-list))))   ;; check if symbol
        (cond ((numberp i)  (setf return-list (cons 'number-type== return-list)))) ;; check if number
        (cond ((integerp i) (progn                                                 ;; check if integer, if yes check even/odd
                              (cond ((oddp i)     (setf return-list (cons 'odd-number-type return-list))))
                              (cond ((evenp i)    (setf return-list (cons 'even-number-type return-list))))
                              (setf return-list (cons 'integer-type return-list)))))     
        (cond ((floatp i)   (setf return-list (cons 'float-type return-list))))    ;; check if float
        (cond ((complexp i) (setf return-list (cons 'complex-type return-list))))  ;; check if complex-number
        (cond ((or (floatp i)                                           
                   (stringp i)
                   (numberp i)  ;; we can check for ;; oddp - evenp for calculating median.
                   (symbolp i)) )  ;; no action
              (t
               (setf return-list (cons 'unknown-type return-list))))))
    (reverse return-list)))          ;; returns list in right order. 



(defun test-if-true-for-a-type (MyList)
  "function test-if-true-for-a-type (arg: list), returns a list. Checks for multiple predicates."
  (let ((return-list '()))
    (dolist (i MyList)
      (progn
        (if (stringp i)              ;; or use (typep i 'string)  -> more allround
            (setf return-list (cons 'string-type return-list)))
        (if (and (numberp i)
                 (integerp i))      
            (setf return-list (cons 'integer-type return-list)))
        (if (and (numberp i)
                 (floatp i))
            (setf return-list (cons 'float-type return-list)))
        (if (and (numberp i)
                 (complexp i))
            (setf return-list (cons 'complex-type return-list)))
        (if (symbolp i)
            (setf return-list (cons 'symbol-type return-list)))
        (if (or (stringp i)
                (symbolp i)
                (integerp i)
                (floatp i)
                (complexp i))
            ()                        ;; if true do nothing (or use: nil).
          (setf return-list (cons 'unknown-type return-list))))) ;; else return 'unknown-type
    (reverse return-list)))           ;; returns list in right order. 



(defun find-type-from-atom (myList &optional type-identifier)
  "function find-type-from-atom (arg: list optional arg: type-identifier), returns a list. Checks if type of atom (from MyList) is available in the type-list."
  (let ((return-list '())             ;; create an empty return list for storing our results.
        (type-list '(integer float string list symbol)))  ;; list with types to recognise.
    (if type-identifier               ;; if the optional argument type-identifier is in use.
        (dolist (i myList)            ;; if true.
          (if (typep i type-identifier)     ;; nested if
              (setf return-list (cons i return-list))    ;; if true cons i in list.
            (setf return-list (cons nil return-list))))  ;; else cons nil.
      (dolist (i myList)              ;; else iterate MyList, outer loop.
        (dolist (j type-list)         ;; nested inner loop.
          (if (typep i j)             ;; check type from atom from list to other list with types
              (setf return-list (cons j return-list))))))  ;; if true, no else
    (reverse return-list)))           ;; use reverse inorder to return the list in right order.                     
    

 



(defvar *variable-name* 127)  ;; a single global variable. use the *name* as a convention.


(defun use-case-function (myList)
  "use-case-function (myList) returns a list."
  (let ((return-list '()))
    (dolist (i myList)
      (case i
        (60              (setf return-list (cons "found-central-c" return-list)))              ;; ok.
        ("central c"     (setf return-list (cons 'found-central-c-as-a-string return-list)))   ;; not ok. use (if (string= i "central c")....
        (c               (setf return-list (cons 60.0 return-list)))                           ;; ok.
        (C4              (setf return-list (cons 60.01 return-list)))                          ;; ok.
        (c-maj           (setf return-list (cons '(60 63 65) return-list)))                    ;; ok.

        (variable-name   (setf return-list (cons 'found-it return-list)))                      ;; ok.
        (*variable-name* (progn 
                           (setf return-list (cons i 
                                                   (cons *variable-name* return-list)))
                           (setf *variable-name* 100)))                                        ;; change binding into 100
        (otherwise       (setf return-list (cons nil return-list)))))                          ;; found nothing: defensive programming !!
    (reverse return-list)))                                                                    ;; returns list in right order. 




;;;; anatomy of a lisp function.
(defun foo () 
  "Documentation foo (): empty function"
  (format t "~%foo - empty function")
  nil)  ;; last element will be returned. in this case it returns a nil.


;; -----------------top-level-function---------------------------
;; (toplevel-function-cond+if)

(defun toplevel-function-cond+if ()
  "toplevel-function-cond+if(), documentation string"

  ;; name name+oct MIDI-key-number freq(Hz) Wavelength (period in ms)
  (format t "~%~A" (test-type-with-one-condition-is-true '(c C4 60 261.63 3.822 "central c" '(1 2 3) 2 "prime" 'my-char-string #'foo)))
  (terpri)

  ;;
  (format t "~%~A" (test-type-with-multiple-conditions-are-true '(1 2.3 "string 1" 'i 2 "another string" #C(1.0 1.0) 'etc)))  ;; quote i used
  (format t "~%~A" (test-type-with-multiple-conditions-are-true '(2 7.2 "string 2" i 2 #C(1.0 1.0) 'etc)))
  (terpri)

  ;;
  (format t "~%~A" (test-if-true-for-a-type '(1 2.3 "central c" 'i 2 "string 1" 'etc)))
  (terpri)

  ;;
  (format t "~%~A" (find-type-from-atom '(1 2.3 "string 1" 'i 2 "string 1" 'etc (1 2 6) nil)))   ;; no optional.
  (format t "~%~A" (find-type-from-atom '(1 2.3 "string 1" 'i 2 "string 1" 'etc) 'string))       ;; with the use of optional: only identify strings.
  (terpri)

  ;;
  (format t "~%~A" (setf *variable-name* 127))
  (format t "~%~A" (use-case-function '(c C4 60 261.63 3.822 "central c" '(1 2 3) 2 "prime" 'c-maj variable-name *variable-name* 'foo)))
  (format t "~%~A" *variable-name*)
  (terpri)
  (terpri))
  

