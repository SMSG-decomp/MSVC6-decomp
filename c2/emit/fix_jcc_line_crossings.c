void __fastcall fix_jcc_line_crossings(c2_function *fn)

{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  c2_tuple *pcVar4;
  c2_tuple *t;
  c2_tuple *anchor;
  uint uVar5;
  int iVar6;
  uint32_t local_48;
  byte local_40;
  byte local_3f;
  char acStack_1f [31];
  
  do {
    bVar3 = false;
    local_48 = 0xffffffff;
    anchor = fn->cfg->first->head;
    if (anchor == (c2_tuple *)0x0) {
      return;
    }
    do {
      switch(anchor->kind) {
      case '\f':
      case '\r':
      case '\x0e':
      case '\x0f':
      case '\x10':
      case '\x11':
      case '\x12':
      case '\x13':
      case '\x14':
      case '\x15':
        uVar5 = anchor->op;
        if ((uVar5 != 0) && (uVar5 < 0x144)) {
          if ((((g_x86_op_flags[uVar5] & 0x10) == 0) &&
              (((uVar5 != 0xc || (anchor->dst->kind != '\x01')) ||
               (((anchor->dst->u18).reg)->id < 0x1d)))) &&
             (((uVar5 != 0xd || (anchor->src->kind != '\x01')) ||
              (((anchor->src->u18).reg)->id < 0x1d)))) {
LAB_1077c52e:
            local_48 = local_48 + anchor->flags12;
          }
          else {
            uVar5 = 0;
            pcVar4 = anchor;
            if (anchor != (c2_tuple *)0x0) {
LAB_1077c484:
              if ((pcVar4->flags & 1) == 0) goto LAB_1077c496;
              if (uVar5 < 0x21) {
                uVar5 = uVar5 + pcVar4->flags12;
                goto LAB_1077c496;
              }
              if (pcVar4 != (c2_tuple *)0x0) {
                if (uVar5 == 0x21) {
                  if (pcVar4->op != 0xf) {
                    if ((pcVar4->op != 0xbb) ||
                       (encode_instruction(pcVar4,&local_40,local_48 + 0x21,0,(c2_fe_symbol *)0x0),
                       local_40 != 0xf)) goto LAB_1077c52e;
                    if (pcVar4->flags12 < 2) {
                      pcVar4 = pcVar4->next;
                      goto joined_r0x1077c546;
                    }
                    if ((local_3f < 0x80) || (0x8f < local_3f)) goto LAB_1077c52e;
                  }
                  uVar2 = anchor->line;
                  if (uVar2 != 0) {
                    g_current_line_abs = fn->line_base + (uint)uVar2;
                    g_cur_line = uVar2;
                  }
                  goto LAB_1077c510;
                }
                pcVar4 = pcVar4->prev;
                bVar1 = pcVar4->flags;
                while ((bVar1 & 1) == 0) {
                  pcVar4 = pcVar4->prev;
                  bVar1 = pcVar4->flags;
                }
                iVar6 = uVar5 - pcVar4->flags12;
                encode_instruction(pcVar4,&local_40,iVar6 + local_48,0,(c2_fe_symbol *)0x0);
                if (acStack_1f[-iVar6] != '\x0f') goto LAB_1077c52e;
                if (0x22U - iVar6 < (uint)pcVar4->flags12) {
                  if (((byte)acStack_1f[-iVar6 + 1] < 0x80) || (0x8f < (byte)acStack_1f[-iVar6 + 1])
                     ) goto LAB_1077c52e;
                  uVar2 = anchor->line;
                  goto joined_r0x1077c675;
                }
                t = pcVar4->next;
                if (t != (c2_tuple *)0x0) {
                  while ((t->flags & 1) == 0) {
                    t = t->next;
                    if (t == (c2_tuple *)0x0) goto switchD_1077c3c8_caseD_16;
                  }
                  if (t != (c2_tuple *)0x0) {
                    encode_instruction(t,&local_40,iVar6 + (uint)pcVar4->flags12 + local_48,0,
                                       (c2_fe_symbol *)0x0);
                    if ((0x7f < local_40) && (local_40 < 0x90)) {
                      uVar2 = anchor->line;
                      goto joined_r0x1077c675;
                    }
                    goto LAB_1077c52e;
                  }
                }
              }
              break;
            }
          }
        }
        break;
      case '\x17':
        local_48 = fn->fsym->offset;
        break;
      case '\x1a':
        anchor->flags12 = '\0';
        local_48 = anchor->src->rank;
      }
switchD_1077c3c8_caseD_16:
      anchor = anchor->next;
    } while (anchor != (c2_tuple *)0x0);
    if (!bVar3) {
      return;
    }
    assign_code_offsets(fn,1);
    relax_branches_iterate(fn);
    assign_code_offsets(fn,1);
  } while( true );
LAB_1077c496:
  pcVar4 = pcVar4->next;
  if (pcVar4 == (c2_tuple *)0x0) goto switchD_1077c3c8_caseD_16;
  goto LAB_1077c484;
joined_r0x1077c546:
  if (pcVar4 == (c2_tuple *)0x0) goto switchD_1077c3c8_caseD_16;
  if ((pcVar4->flags & 1) != 0) {
    if (pcVar4 != (c2_tuple *)0x0) {
      encode_instruction(pcVar4,&local_40,local_48 + 0x22,0,(c2_fe_symbol *)0x0);
      if ((0x7f < local_40) && (local_40 < 0x90)) {
        uVar2 = anchor->line;
joined_r0x1077c675:
        if (uVar2 != 0) {
          g_current_line_abs = fn->line_base + (uint)uVar2;
          g_cur_line = uVar2;
        }
LAB_1077c510:
        pcVar4 = tuple_new_nooperands(0xa9,0x1001,tuple_insert_after,anchor);
        pcVar4->flags12 = '\x01';
        bVar3 = true;
      }
      goto LAB_1077c52e;
    }
    goto switchD_1077c3c8_caseD_16;
  }
  pcVar4 = pcVar4->next;
  goto joined_r0x1077c546;
}

