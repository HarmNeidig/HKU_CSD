;;;;***********************************************
;;;; HISTORY: started 120216
;;;; functions with cons and append.
;;;; michel.koenders@hku.nl no copyright: free to alter or use in any way...
;;;;***********************************************
;;;; 170217 mk, revision
;;;; lisp functions used: cons, append, length, dolist, dotimes, format
;;;; 240217 mk, revision
;;;; 110419 mk, tweeks on text.



(defvar *MyList*  '() "*MyList* Dus ook een variable heeft een documentation string")       ;; global scope variable


;; ----------------- functions ---------------------------
(defun copyfunction-cons (arg1-list arg2-list)
  "copyfunction-cons (arg1-list arg2-list) copies a list by using dolist and cons"
  (let ((a '())             ;; bind 2 local variables to an empty list.
        (b '()))
    (dolist (i arg1-list)   ;; dolist iterates a list and binds the car, first element of the list to i, until the list is empty.
      (setf a (cons i a)))
    (dolist (j arg2-list)
      (setf b (cons j b)))

    (print a)
    (print b)               ;; reverse the list otherwise list is turned.
    (print (reverse b))     ;; reversed version.
    (terpri))
  )


(defun copyfunction-append (arg1-list arg2-list)
  "copyfunction-append (arg1-list arg2-list), copies a list by using dolist and append"
  (let ((a '())
        (b '()))
    (dolist (i arg1-list)
      (setf a (append a (list i))))
    (dolist (j arg2-list)
      (setf b (append b (list j))))
    (print a)
    (print b)))   ;;  we do not have to revere the append list.

(defun print-every-item-of-list (arg1-list arg2-list)
  "print-every-item-of-list (arg1-list arg2-list) print items of a list by using format"
  (let ((a '())
        (b '())
        (the-size-of-the-list 0))  ;; initial binding to zero.
    (dolist (i arg1-list)
      (let ((c 0))   ;; bind new variable c.
        (setf c i)
        (format t "~% c = ~D" c)))    ;; format = very powerfull print function.
    ;; second part of the function uses the second argument.
    (setf the-size-of-the-list (length arg2-list)) ;; find the length (or size) of our list.
    (dotimes (j the-size-of-the-list)
      (setf b (nth j arg2-list))      ;; use second list.
      (print b))   
    (print a)
    (print b)
  ;  (print c)    ;; error ! if we want to print c outside it's scope, and is therefore unknown.
    ))



;; ----------------top-function----------------------------
;; (toplevel-function-function+list)
(defun toplevel-function-function+list ()
  "toplevel-function-function+list(), documentation string"

;;  (setf *myList* '())       ;; use in case global *MyList* needs to be empty '() 

  (copyfunction-cons '(1 "a name string" a 4) '(7 10))
  (print *MyList*)
  (setf *MyList* (copyfunction-append '(2 "an other name string" b 4) '(11 20)))  ;; new binding
  (print *MyList*)
  (print-every-item-of-list '(3 "a third name string" a 8) '(21 30)))



;;; ******