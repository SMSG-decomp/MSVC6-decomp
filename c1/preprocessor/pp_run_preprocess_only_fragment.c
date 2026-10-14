void __cdecl pp_run_preprocess_only_fragment(void *writer)

{
  char cVar1;
  c1_token *pcVar2;
  uint uVar3;
  char *pcVar4;
  
  do {
    pcVar2 = token_next(&g_token_position);
    switch((uint)pcVar2->code) {
    case 0:
    case 0x6d:
      return;
    case 1:
    case 0x88:
    case 0xf2:
    case 0xf4:
      break;
    default:
      uVar3 = 0xffffffff;
      pcVar4 = g_token_spelling[pcVar2->code];
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      (*writer)(g_token_spelling[pcVar2->code],~uVar3 - 1,1,_iob_exref + 0x20);
      break;
    case 7:
    case 0x65:
      (*writer)((pcVar2->value).ptr,(pcVar2->value).string.length - 1,1,_iob_exref + 0x20);
    }
  } while( true );
}

