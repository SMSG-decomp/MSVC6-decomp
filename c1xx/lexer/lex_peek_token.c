char * __fastcall lex_peek_token(uint *stream)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  pcVar3 = (char *)(**(code **)(**(int **)stream[1] + 4))();
  cVar1 = *pcVar3;
  while ((cVar1 == -9 && (uVar2 = stream[1], *(int *)(uVar2 + 0xc) == 1))) {
    if (uVar2 != 0) {
      stream[1] = *(uint *)(uVar2 + 4);
      *stream = *(uint *)(uVar2 + 8);
      if (*(code **)(uVar2 + 0x10) != (code *)0x0) {
        (**(code **)(uVar2 + 0x10))();
      }
    }
    pcVar3 = (char *)(**(code **)(**(int **)stream[1] + 4))();
    cVar1 = *pcVar3;
  }
  return pcVar3;
}

