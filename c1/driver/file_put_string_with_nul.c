void __cdecl file_put_string_with_nul(char *s,FILE *file)

{
  char cVar1;
  int iVar2;
  
  do {
    iVar2 = file->_cnt + -1;
    file->_cnt = iVar2;
    if (iVar2 < 0) {
      _flsbuf((int)*s,file);
    }
    else {
      *file->_ptr = *s;
      file->_ptr = file->_ptr + 1;
    }
    cVar1 = *s;
    s = s + 1;
  } while (cVar1 != '\0');
  return;
}

