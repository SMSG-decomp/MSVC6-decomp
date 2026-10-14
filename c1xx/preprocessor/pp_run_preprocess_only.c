void __cdecl pp_run_preprocess_only(void)

{
  char cVar1;
  byte *pbVar2;
  uint uVar3;
  char *pcVar4;
  
  do {
    pbVar2 = token_next((c1_token_reader *)&g_token_position);
    switch((uint)*pbVar2) {
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
      pcVar4 = g_token_spelling[*pbVar2];
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      fwrite(g_token_spelling[*pbVar2],~uVar3 - 1,1,(FILE *)(_iob_exref + 0x20));
      break;
    case 7:
    case 0x65:
      fwrite(*(void **)(pbVar2 + 8),*(ushort *)(pbVar2 + 0xc) - 1,1,(FILE *)(_iob_exref + 0x20));
    }
  } while( true );
}

