(defun functie-naam(arg1 arg2)
"documentation string"
;dit  is ook een comment
)
;;;;dit is een hele belangerijke comment

;;globale constant
(defconstant +my-global-const+)

;;globale variable
(defvar *my-global-var* nil "documantation string")

(defun functie-twee (arg1 arg2 &optional arg3)
  "documentation string, functie-zonder-output (arg1, arg2) => result van + arg1 arg2"
  (let* ((result 0)
         (result2 result));;0 is the initial value, let is defining variables
    (if arg3
        (setf result (+ arg1 arg2 arg3))
      (setf result (+ arg1 arg2)))
    (print result)
    nil
    ))

(defun aftrekken (arg1 arg2 &optional arg3)
  (let