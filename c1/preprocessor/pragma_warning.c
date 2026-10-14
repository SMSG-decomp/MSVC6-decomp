int __cdecl pragma_warning(void)

{
  c1_u8 cVar1;
  c1_token *pcVar2;
  int iVar3;
  c1_type *pcVar4;
  c1_type *pcVar5;
  byte bVar6;
  char *pcVar7;
  bool bVar8;
  c1_u32 cVar9;
  uint uVar10;
  int message_arg;
  
code_r0x1062b583:
  bVar6 = 1;
LAB_1060a040:
  do {
    while( true ) {
      pcVar2 = pragma_warn_expected_token('6');
      if (pcVar2 == (c1_token *)0x0) {
        return 0;
      }
      pcVar2 = token_next(&g_token_position);
      cVar1 = pcVar2->code;
      while (cVar1 == 'e') {
        pragma_warning_check_number((pcVar2->value).words[2],bVar6);
        pcVar2 = token_next(&g_token_position);
        cVar1 = pcVar2->code;
      }
      if (pcVar2->code == '~') {
        iVar3 = pragma_dispatch_return_zero_tail();
        return iVar3;
      }
      if (pcVar2->code != '\x7f') {
        (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar2);
        pragma_warn_expected_token('~');
        return 0;
      }
      pcVar2 = token_next(&g_token_position);
      cVar1 = pcVar2->code;
      if (cVar1 != '\x06') break;
      pcVar7 = "disable";
      pcVar5 = ((pcVar2->value).node)->type;
      pcVar4 = pcVar5;
      do {
        bVar6 = (byte)pcVar4->code;
        bVar8 = bVar6 < (byte)*pcVar7;
        if (bVar6 != *pcVar7) {
LAB_1062b5a1:
          iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
          goto LAB_1060a033;
        }
        if (bVar6 == 0) break;
        bVar6 = *(byte *)((int)&pcVar4->code + 1);
        bVar8 = bVar6 < (byte)pcVar7[1];
        if (bVar6 != pcVar7[1]) goto LAB_1062b5a1;
        pcVar4 = (c1_type *)&pcVar4->flags;
        pcVar7 = pcVar7 + 2;
      } while (bVar6 != 0);
      iVar3 = 0;
LAB_1060a033:
      if (iVar3 == 0) {
        bVar6 = 0xd;
      }
      else {
        pcVar7 = "error";
        pcVar4 = pcVar5;
        do {
          bVar6 = (byte)pcVar4->code;
          bVar8 = bVar6 < (byte)*pcVar7;
          if (bVar6 != *pcVar7) {
LAB_1062b5e6:
            iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
            goto LAB_1062b5d8;
          }
          if (bVar6 == 0) break;
          bVar6 = *(byte *)((int)&pcVar4->code + 1);
          bVar8 = bVar6 < (byte)pcVar7[1];
          if (bVar6 != pcVar7[1]) goto LAB_1062b5e6;
          pcVar4 = (c1_type *)&pcVar4->flags;
          pcVar7 = pcVar7 + 2;
        } while (bVar6 != 0);
        iVar3 = 0;
LAB_1062b5d8:
        if (iVar3 == 0) {
          bVar6 = 0xe;
        }
        else {
          pcVar7 = "once";
          do {
            bVar6 = (byte)pcVar5->code;
            bVar8 = bVar6 < (byte)*pcVar7;
            if (bVar6 != *pcVar7) {
LAB_1062b628:
              iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
              goto LAB_1062b61a;
            }
            if (bVar6 == 0) break;
            bVar6 = *(byte *)((int)&pcVar5->code + 1);
            bVar8 = bVar6 < (byte)pcVar7[1];
            if (bVar6 != pcVar7[1]) goto LAB_1062b628;
            pcVar5 = (c1_type *)&pcVar5->flags;
            pcVar7 = pcVar7 + 2;
          } while (bVar6 != 0);
          iVar3 = 0;
LAB_1062b61a:
          if (iVar3 != 0) {
            pcVar7 = "push";
            pcVar5 = ((pcVar2->value).node)->type;
            pcVar4 = pcVar5;
            goto LAB_1062b665;
          }
          bVar6 = 5;
        }
      }
    }
    if (cVar1 == 'e') {
      switch((pcVar2->value).words[2]) {
      case 1:
        goto code_r0x1062b583;
      case 2:
        bVar6 = 2;
        goto LAB_1060a040;
      case 3:
        bVar6 = 3;
        goto LAB_1060a040;
      case 4:
        bVar6 = 4;
        goto LAB_1060a040;
      default:
        diag_warning(1,0x268,(pcVar2->value).words[2],1,4);
        pragma_skip_to_dash(pcVar2);
        return 0;
      }
    }
    if (cVar1 != 'g') goto LAB_1062b7aa;
    bVar6 = 0;
  } while( true );
  while( true ) {
    bVar6 = *(byte *)((int)&pcVar4->code + 1);
    bVar8 = bVar6 < (byte)pcVar7[1];
    if (bVar6 != pcVar7[1]) goto LAB_1062b6db;
    pcVar4 = (c1_type *)&pcVar4->flags;
    pcVar7 = pcVar7 + 2;
    if (bVar6 == 0) break;
LAB_1062b665:
    bVar6 = (byte)pcVar4->code;
    bVar8 = bVar6 < (byte)*pcVar7;
    if (bVar6 != *pcVar7) {
LAB_1062b6db:
      iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      goto LAB_1062b68b;
    }
    if (bVar6 == 0) break;
  }
  iVar3 = 0;
LAB_1062b68b:
  if (iVar3 == 0) {
    pragma_warning_push();
    pcVar2 = token_next(&g_token_position);
    bVar6 = pcVar2->code;
    if (bVar6 == 0x37) {
      pcVar2 = pragma_warn_expected_token('e');
      if (pcVar2 == (c1_token *)0x0) {
        return 0;
      }
      cVar9 = (pcVar2->value).words[2];
      if ((0 < (int)cVar9) && ((int)cVar9 < 5)) {
        g_warning_state->level = cVar9;
        pragma_warn_expected_token('~');
        return 0;
      }
      uVar10 = 4;
      message_arg = 1;
      iVar3 = 0x268;
    }
    else {
      if (bVar6 == 0x7e) {
        return 0;
      }
      uVar10 = (uint)bVar6;
      message_arg = 0x7e;
      cVar9 = 0x37;
      iVar3 = 0xc4;
    }
    diag_warning(1,iVar3,cVar9,message_arg,uVar10);
    pragma_skip_to_dash(pcVar2);
    return 0;
  }
  pcVar7 = "pop";
  do {
    bVar6 = (byte)pcVar5->code;
    bVar8 = bVar6 < (byte)*pcVar7;
    if (bVar6 != *pcVar7) {
LAB_1062b730:
      iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      goto LAB_1062b70f;
    }
    if (bVar6 == 0) break;
    bVar6 = *(byte *)((int)&pcVar5->code + 1);
    bVar8 = bVar6 < (byte)pcVar7[1];
    if (bVar6 != pcVar7[1]) goto LAB_1062b730;
    pcVar5 = (c1_type *)&pcVar5->flags;
    pcVar7 = pcVar7 + 2;
  } while (bVar6 != 0);
  iVar3 = 0;
LAB_1062b70f:
  if (iVar3 == 0) {
    pragma_warning_pop();
    pragma_warn_expected_token('~');
    return 0;
  }
LAB_1062b7aa:
  diag_warning(1,0x267);
  pragma_skip_to_dash(pcVar2);
  return 0;
}

