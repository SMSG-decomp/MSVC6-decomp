void __cdecl diag_write_line_stderr(char *line)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0xffffffff;
  pcVar3 = line;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  fwrite(line,~uVar2 - 1,1,(FILE *)(_iob_exref + 0x40));
  fwrite("\n",1,1,(FILE *)(_iob_exref + 0x40));
  fflush((FILE *)(_iob_exref + 0x40));
  return;
}

