void __cdecl file_put_string_with_nul(char *text,FILE *file)

{
  char cVar1;
  int iVar2;
  
  do {
    iVar2 = file->_cnt + -1;
    file->_cnt = iVar2;
    if (iVar2 < 0) {
      _flsbuf((int)*text,(FILE *)file);
    }
    else {
      *file->_ptr = *text;
      file->_ptr = file->_ptr + 1;
    }
    cVar1 = *text;
    text = text + 1;
  } while (cVar1 != '\0');
  return;
}

