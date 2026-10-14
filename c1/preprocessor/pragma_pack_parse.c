void pragma_pack_parse(void)

{
  c1_u8 cVar1;
  byte bVar2;
  fe_pack_cell *pfVar3;
  c1_token *pcVar4;
  c1_type *pcVar5;
  c1_type *pcVar6;
  c1_u32 name;
  int iVar7;
  int iVar8;
  char *pcVar9;
  bool bVar10;
  
  iVar8 = 0;
  iVar7 = 0;
  name = 0;
  pcVar4 = pragma_warn_expected_token('v');
  if (pcVar4 == (c1_token *)0x0) {
    return;
  }
  pcVar4 = token_next(&g_token_position);
  cVar1 = pcVar4->code;
  if (cVar1 != '\x06') {
    if (cVar1 != 'e') {
      if (cVar1 != '~') {
        (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar4);
        pragma_warn_expected_token('~');
        return;
      }
      iVar7 = g_opt_Zp;
      if (g_opt_Zp == -1) {
        iVar7 = 8;
      }
      goto LAB_1061190d;
    }
    goto LAB_106118cf;
  }
  pcVar9 = "push";
  pcVar6 = ((pcVar4->value).node)->type;
  pcVar5 = pcVar6;
  do {
    bVar2 = (byte)pcVar5->code;
    bVar10 = bVar2 < (byte)*pcVar9;
    if (bVar2 != *pcVar9) {
LAB_10611929:
      iVar8 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
      goto LAB_1061188b;
    }
    if (bVar2 == 0) break;
    bVar2 = *(byte *)((int)&pcVar5->code + 1);
    bVar10 = bVar2 < (byte)pcVar9[1];
    if (bVar2 != pcVar9[1]) goto LAB_10611929;
    pcVar5 = (c1_type *)&pcVar5->flags;
    pcVar9 = pcVar9 + 2;
  } while (bVar2 != 0);
  iVar8 = 0;
LAB_1061188b:
  if (iVar8 == 0) {
    iVar8 = 1;
  }
  else {
    pcVar9 = "pop";
    do {
      bVar2 = (byte)pcVar6->code;
      bVar10 = bVar2 < (byte)*pcVar9;
      if (bVar2 != *pcVar9) {
LAB_1062a98d:
        iVar8 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        goto LAB_10611964;
      }
      if (bVar2 == 0) break;
      bVar2 = *(byte *)((int)&pcVar6->code + 1);
      bVar10 = bVar2 < (byte)pcVar9[1];
      if (bVar2 != pcVar9[1]) goto LAB_1062a98d;
      pcVar6 = (c1_type *)&pcVar6->flags;
      pcVar9 = pcVar9 + 2;
    } while (bVar2 != 0);
    iVar8 = 0;
LAB_10611964:
    if (iVar8 != 0) {
      diag_warning(1,0x4f,6);
      return;
    }
    iVar8 = 2;
  }
  pcVar4 = token_next(&g_token_position);
  if (pcVar4->code != '~') {
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar4);
    pcVar4 = pragma_warn_expected_token('7');
    if (pcVar4 == (c1_token *)0x0) {
      return;
    }
    pcVar4 = token_next(&g_token_position);
    if (pcVar4->code == '\x06') {
      name = (pcVar4->value).words[0];
      pcVar4 = token_next(&g_token_position);
      if (pcVar4->code != '~') {
        (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar4);
        pcVar4 = pragma_warn_expected_token('7');
        if (pcVar4 == (c1_token *)0x0) {
          return;
        }
        pcVar4 = pragma_warn_expected_token('e');
        if (pcVar4 == (c1_token *)0x0) {
          return;
        }
        goto LAB_106118cf;
      }
    }
    else if (pcVar4->code == 'e') {
LAB_106118cf:
      iVar7 = pragma_check_pack_value((pcVar4->value).words[2]);
      pcVar4 = pragma_warn_expected_token('~');
      if (pcVar4 == (c1_token *)0x0) {
        return;
      }
    }
  }
  if (iVar8 != 0) {
    if (iVar8 == 1) {
      pragma_pack_push(iVar7,name);
      return;
    }
    pragma_pack_pop(iVar7,name);
    return;
  }
LAB_1061190d:
  pfVar3 = g_pack_stack->top;
  iVar7 = pragma_check_pack_value(iVar7);
  pfVar3->packing = iVar7;
  return;
}

