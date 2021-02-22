;;;; ******************************************************************************************
;;;; ***** top level loader xfasl. files.       /2017                    *****
;;;; bevat in de juiste volgorde alle files + juiste directories voor de gehele omgeving. *****
;;;; ******************************************************************************************
;;;; *** HISTORY ***
;;;; ***************
;;;; 240217 mk, added 2 files. (total 2)  ;; array-lists.xfasl; conditions+if.xfasl
;;;; 030317 mk, tweeks.
;;;; 210220 mk, tweeks on date.
;;;; 010221 mk, tweeks on date.
;;;; ************************************************************************************************************





;;; first print memory space.
(room 'nil)


;; in case we need a package definition.
;;;; create the top package
;;(eval-when (:compile-toplevel :load-toplevel :execute)
;;  (defpackage "CACEIV-PACKAGE"
;;    (:use "CAPI" "CL-USER" "CLOS")
;;    (:add-use-defaults)))

;; and make it the in package
;;(in-package "CACEIV-PACKAGE")


(setf *read-default-float-format* 'double-float)  ;; or use single-float

;; *******************
;; ***** GLOBALS *****
;; *******************
(defvar *last-LISP-FASL-version*    "v1.010221") ;; for latest version of file changes
(defvar *max-LISP-files* 3)                      ;; this is a variable max file counter mk 240217, 
                                                 ;; used for (error) checking the total number of files loaded.
(defvar *xfastload-module-counter* 0)            ;; this is a variable counter mk 240217,
(setf *xfastload-module-counter* 0)              ;; when file is reused ne sure the variable has the right value.






;;; *********************************************************************************************************
;;; ***** THIS needs to be done first -> I need the global *User-Dir*; so now al lisp are transportable *****
;;; *********************************************************************************************************
;; Directory - where am I ? 240217, mk
(defvar *User-Dir* "Users/michelkoenders/Documents/Lisp/")
(setf *User-fastload-Dir* "Users/michelkoenders/Documents/Lisp/")


;; *************************************************************************************
;; set the start-up directory
(defvar *LISP-Load-Compiled-Files* (concatenate 'string *User-fastload-Dir* "Lisp compiled XFASL files/"))
(setf *LISP-Load-Compiled-Files* (concatenate 'string *User-fastload-Dir* "Lisp compiled XFASL files/"))


;;;;; 32-bit
;(load (concatenate 'string *LISP-Load-Compiled-Files* "simple-function+list.xfasl"))(incf *xfastload-module-counter*)   ;; file 1
;(load (concatenate 'string *LISP-Load-Compiled-Files* "array-lists.xfasl"))(incf *xfastload-module-counter*)            ;; file 2
;(load (concatenate 'string *LISP-Load-Compiled-Files* "conditions-if.xfasl"))(incf *xfastload-module-counter*)          ;; file 3 ... etc.!

;;;;; 64-bit
(load (concatenate 'string *LISP-Load-Compiled-Files* "simple-function+list.64xfasl"))(incf *xfastload-module-counter*)   ;; file 1
(load (concatenate 'string *LISP-Load-Compiled-Files* "array-lists.64xfasl"))(incf *xfastload-module-counter*)            ;; file 2
(load (concatenate 'string *LISP-Load-Compiled-Files* "conditions-if.64xfasl"))(incf *xfastload-module-counter*)          ;; file 3 ... etc.!



;; *************************************************************************************
;; just some GUI....
(format nil "~%~%")
(format nil ">")
(format nil "> Starting to load all LISP fastload modules.")
(format nil "-------------------------------------------------------------------")



;; check for the right machine-architecture/processor.
(defun machine-architecture ()
      #+:x86 "i386"
      #+:x64 "X64"
      #-(or :x86 :x64) "unknown")

(terpri)
(terpri)
(princ '________________________________________________________________________)
(terpri)
(terpri)



(format nil "________________________________________________________________________~%~%")

(format nil "  LISP:......... ready initializing LISP files.~%")

(room t)  ;; shows memory
(format nil "________________________________________________________________________~%~%~%")

(format nil "***********************************************************************")
(format nil "***********************************************************************")
(format nil "*****                                                             *****")
(format nil "***** Lisp type:        ~10D                                *****" (lisp-implementation-type))
(format nil "***** Lisp version: ~10D                                    *****" (lisp-implementation-version))
(format nil "***** Lisp image name: ~10D *****" (lisp-image-name))
(format nil "*****                                                             *****")
;(format nil "***** Time:~12D   Date:~12D                       *****" (get-time-string)(get-date-string))
(format nil "***** Machine Architecture: ~10D                            *****" (machine-architecture))
(format nil "***** Machine type:         ~10D                            *****" (machine-type))
(format nil "***** Machine version:      ~10D                            *****" (machine-version))
(format nil "***** Machine name:         ~20D                 *****" (machine-instance))
(format nil "*****                                                             *****")
(format nil "***** Software version: ~10D                                *****" (software-version))
(format nil "***** Software type:    ~10D                                *****" (software-type))
(format nil "*****                                                             *****")
(format nil "*****                                                             *****")
(if (= *xfastload-module-counter* *max-LISP-files*)
    (progn
      (format nil "***** All available LISP Modules have been loaded.               *****")
      (format nil "***** Ready for use... © Michél Koenders 2021.               *****")
      (format nil "*****                                                             *****")
      (format nil "***********************************************************************")
      (format nil "***********************************************************************~%~%"))
  (progn 
    (format  nil "~%~%ERROR: SOME FILES HAVE NOT BEEN LOADED; WE ARE MISSING: ~10D  FILES.*****~%~%" (- *max-LISP-files* *xfastload-module-counter*))))

(room 'nil)



;;***********************************************************************************
(format t "~%~% LISP --- LISP XFASL.lisp --- version: ~10A" *last-LISP-FASL-version*)
;;***********************************************************************************



