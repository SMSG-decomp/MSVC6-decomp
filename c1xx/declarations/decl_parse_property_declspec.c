void __cdecl decl_parse_property_declspec(byte *spec)

{
  byte bVar1;
  undefined4 *puVar2;
  c1xx_token *pcVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  void *pvVar7;
  char *pcVar8;
  bool bVar9;
  short n;
  
  if ((spec[3] & 0x80) == 0) {
    puVar2 = arena_alloc(g_arenas,8);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
      puVar2[1] = 0;
    }
    *(undefined4 **)(spec + 8) = puVar2;
    spec[3] = spec[3] | 0x80;
  }
  pcVar3 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
  if (pcVar3->code == 0x76) {
    do {
      pcVar3 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
      if (pcVar3->code != '\x06') {
        diag_error(0x3b,0x73,g_token_spelling[pcVar3->code]);
        *spec = *spec | 8;
        parse_skip_tokens_to_one_of(pcVar3,0x7e,1);
        return;
      }
      pcVar8 = "get";
      pbVar6 = *(byte **)((int)pcVar3->value + 4);
      pbVar4 = pbVar6;
      do {
        bVar1 = *pbVar4;
        bVar9 = bVar1 < (byte)*pcVar8;
        if (bVar1 != *pcVar8) {
LAB_104581b7:
          iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
          goto LAB_10458137;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar4[1];
        bVar9 = bVar1 < (byte)pcVar8[1];
        if (bVar1 != pcVar8[1]) goto LAB_104581b7;
        pbVar4 = pbVar4 + 2;
        pcVar8 = pcVar8 + 2;
      } while (bVar1 != 0);
      iVar5 = 0;
LAB_10458137:
      if (iVar5 == 0) {
        if (**(int **)(spec + 8) != 0) {
          diag_error(0x308);
        }
        bVar9 = true;
      }
      else {
        pcVar8 = "put";
        do {
          bVar1 = *pbVar6;
          bVar9 = bVar1 < (byte)*pcVar8;
          if (bVar1 != *pcVar8) {
LAB_10458210:
            iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
            goto LAB_104581ea;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar6[1];
          bVar9 = bVar1 < (byte)pcVar8[1];
          if (bVar1 != pcVar8[1]) goto LAB_10458210;
          pbVar6 = pbVar6 + 2;
          pcVar8 = pcVar8 + 2;
        } while (bVar1 != 0);
        iVar5 = 0;
LAB_104581ea:
        if (iVar5 != 0) {
          diag_error(0x3d,pcVar3->value);
          *spec = *spec | 8;
          parse_skip_tokens_to_one_of(pcVar3,0x7e,1);
          return;
        }
        if (*(int *)(*(int *)(spec + 8) + 4) != 0) {
          diag_error(0x309);
        }
        bVar9 = false;
      }
      pcVar3 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
      if (pcVar3->code != '4') {
        if (pcVar3->code == 6) {
          pvVar7 = pcVar3->value;
          n = 0x92;
        }
        else {
          pvVar7 = (void *)(uint)pcVar3->code;
          n = 0x8f;
        }
        diag_error(n,0x34,pvVar7);
        *spec = *spec | 8;
        parse_skip_tokens_to_one_of(pcVar3,0x7e,1);
        return;
      }
      pcVar3 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
      if (pcVar3->code != '\x06') {
        diag_error(0x3b,0x73,g_token_spelling[pcVar3->code]);
        *spec = *spec | 8;
        parse_skip_tokens_to_one_of(pcVar3,0x7e,1);
        return;
      }
      if (bVar9) {
        **(undefined4 **)(spec + 8) = pcVar3->value;
      }
      else {
        *(void **)(*(int *)(spec + 8) + 4) = pcVar3->value;
      }
      pcVar3 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
      if (pcVar3->code == 0x7e) {
        return;
      }
    } while (pcVar3->code == 0x37);
    pcVar8 = g_token_spelling[pcVar3->code];
  }
  else {
    pcVar8 = g_token_spelling[pcVar3->code];
  }
  diag_error(0x3b,0x73,pcVar8);
  *spec = *spec | 8;
  parse_skip_tokens_to_one_of(pcVar3,0x7e,1);
  return;
}

