void __cdecl pragma_pack_parse(void)

{
  byte bVar1;
  c1_pack_cell *pcVar2;
  uchar *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  int n;
  int iVar7;
  char *pcVar8;
  bool bVar9;
  
  iVar7 = 0;
  n = 0;
  iVar6 = 0;
  puVar3 = pragma_warn_expected_token('v');
  if (puVar3 == (uchar *)0x0) {
    return;
  }
  pbVar4 = token_next((c1_token_reader *)&g_token_position);
  bVar1 = *pbVar4;
  if (bVar1 != 6) {
    if (bVar1 != 0x65) {
      if (bVar1 != 0x7e) {
        (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar4);
        pragma_warn_expected_token('~');
        return;
      }
      n = g_opt_Zp;
      if (g_opt_Zp == -1) {
        n = 8;
      }
      goto LAB_10438f23;
    }
    goto LAB_10438ee5;
  }
  pcVar8 = "push";
  pbVar4 = *(byte **)(*(int *)(pbVar4 + 8) + 4);
  pbVar5 = pbVar4;
  do {
    bVar1 = *pbVar5;
    bVar9 = bVar1 < (byte)*pcVar8;
    if (bVar1 != *pcVar8) {
LAB_10438f3f:
      iVar7 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
      goto LAB_10438ea1;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar5[1];
    bVar9 = bVar1 < (byte)pcVar8[1];
    if (bVar1 != pcVar8[1]) goto LAB_10438f3f;
    pbVar5 = pbVar5 + 2;
    pcVar8 = pcVar8 + 2;
  } while (bVar1 != 0);
  iVar7 = 0;
LAB_10438ea1:
  if (iVar7 == 0) {
    iVar7 = 1;
  }
  else {
    pcVar8 = "pop";
    do {
      bVar1 = *pbVar4;
      bVar9 = bVar1 < (byte)*pcVar8;
      if (bVar1 != *pcVar8) {
LAB_1045eb8e:
        iVar7 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_10438f7a;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar9 = bVar1 < (byte)pcVar8[1];
      if (bVar1 != pcVar8[1]) goto LAB_1045eb8e;
      pbVar4 = pbVar4 + 2;
      pcVar8 = pcVar8 + 2;
    } while (bVar1 != 0);
    iVar7 = 0;
LAB_10438f7a:
    if (iVar7 != 0) {
      diag_warning(1,0x4f,6);
      return;
    }
    iVar7 = 2;
  }
  pbVar4 = token_next((c1_token_reader *)&g_token_position);
  if (*pbVar4 != 0x7e) {
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar4);
    puVar3 = pragma_warn_expected_token('7');
    if (puVar3 == (uchar *)0x0) {
      return;
    }
    pbVar4 = token_next((c1_token_reader *)&g_token_position);
    if (*pbVar4 == 6) {
      iVar6 = *(int *)(pbVar4 + 8);
      pbVar4 = token_next((c1_token_reader *)&g_token_position);
      if (*pbVar4 != 0x7e) {
        (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar4);
        puVar3 = pragma_warn_expected_token('7');
        if (puVar3 == (uchar *)0x0) {
          return;
        }
        pbVar4 = pragma_warn_expected_token('e');
        if (pbVar4 == (byte *)0x0) {
          return;
        }
        goto LAB_10438ee5;
      }
    }
    else if (*pbVar4 == 0x65) {
LAB_10438ee5:
      n = pragma_check_pack_value(*(int *)(pbVar4 + 0x10));
      puVar3 = pragma_warn_expected_token('~');
      if (puVar3 == (uchar *)0x0) {
        return;
      }
    }
  }
  if (iVar7 != 0) {
    if (iVar7 == 1) {
      pragma_pack_push(n,iVar6);
      return;
    }
    pragma_pack_pop(n,iVar6);
    return;
  }
LAB_10438f23:
  pcVar2 = g_pack_stack->top;
  iVar6 = pragma_check_pack_value(n);
  pcVar2->packing = iVar6;
  return;
}

