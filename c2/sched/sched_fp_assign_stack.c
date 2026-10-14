void __fastcall sched_fp_assign_stack(c2_tuple *ctx)

{
  c2_symbol *pcVar1;
  c2_operand *pcVar2;
  c2_operand **ppcVar3;
  short sVar4;
  ushort uVar5;
  int iVar6;
  c2_operand *pcVar7;
  c2_symbol **ppcVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  c2_operand *pcVar12;
  c2_operand *local_c;
  short local_8;
  
  do {
    if (ctx == (c2_tuple *)0x0) {
      return;
    }
    if ((ctx->flags & 1) != 0) {
      uVar5 = ctx->type & 0xf000;
      if (uVar5 == 0x4000) {
LAB_1077abdf:
        if (((ctx->kind != '\x0e') && (uVar5 != 0x4000)) && (ctx->op != 0x5b)) goto LAB_1077ac99;
      }
      else if (ctx->kind != '\x0e') {
        if (ctx->op != 0x5b) goto LAB_1077ac99;
        goto LAB_1077abdf;
      }
      pcVar7 = ctx->dst;
      pcVar12 = ctx->src;
      iVar6 = x87_stack_effect(ctx);
      if (ctx->op == 0x162) {
        iVar9 = (int)g_sched_fp_tos;
        ppcVar8 = g_sched_fp_stack + iVar9;
        iVar6 = iVar9;
        while( true ) {
          if (0x10799277 < (int)ppcVar8) {
            ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\schedmd.c",0x9e3);
          }
          if (*ppcVar8 == pcVar12->sym->storage) break;
          iVar6 = iVar6 + 1;
          ppcVar8 = ppcVar8 + 1;
        }
        iVar6 = iVar6 - iVar9;
        (pcVar12->u18).reg = g_reg_symbols + iVar6 + 0x1f;
        ppcVar8 = g_sched_fp_stack + iVar9;
        while( true ) {
          if (0x10799277 < (int)ppcVar8) {
            ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\schedmd.c",0x9e3);
          }
          if (*ppcVar8 == pcVar12->sym->storage) break;
          iVar9 = iVar9 + 1;
          ppcVar8 = ppcVar8 + 1;
        }
        pcVar1 = pcVar7->sym->storage;
        (pcVar7->u18).reg = g_reg_symbols + iVar6 + 0x1f;
        g_sched_fp_stack[iVar9] = pcVar1;
      }
      else if (((((ctx->kind == '\x0e') || (iVar9 = x87_op_pushes_stack(ctx), iVar9 != 0)) ||
                ((pcVar12 == (c2_operand *)0x0 ||
                 ((pcVar12->kind != '\x01' || (pcVar1 = pcVar12->sym, pcVar1->cls != '\x03')))))) ||
               (pcVar1->def == (c2_tuple *)0x0)) ||
              (((((pcVar2 = pcVar12->next, pcVar2 == (c2_operand *)0x0 || (pcVar2->kind != '\x01'))
                 || (pcVar2->sym->cls != '\x03')) ||
                ((pcVar2->sym->def == (c2_tuple *)0x0 || ((pcVar2->type & 0xf000) != 0x4000)))) ||
               ((pcVar7->type & 0xf000) != 0x4000)))) {
        pcVar12 = (c2_operand *)0x0;
        local_c = (c2_operand *)0x0;
        local_8 = 0;
        pcVar7 = ctx->src;
        sVar4 = 0;
        if (pcVar7 != (c2_operand *)0x0) {
          do {
            local_8 = sVar4;
            pcVar2 = local_c;
            if (((pcVar7->kind == '\x01') && (pcVar1 = pcVar7->sym, pcVar1->cls == '\x03')) &&
               ((pcVar1->def != (c2_tuple *)0x0 && ((pcVar7->type & 0xf000) == 0x4000)))) {
              if (pcVar1->def->op == 0x19e) {
                (pcVar7->u18).reg = g_reg_symbols + pcVar7->rank + 0x1f;
              }
              else {
                local_8 = local_8 + 1;
                pcVar12 = pcVar7;
                pcVar2 = pcVar7;
                if (pcVar7->rank != 0) {
                  iVar9 = (int)g_sched_fp_tos;
                  ppcVar8 = g_sched_fp_stack + iVar9;
                  iVar6 = iVar9;
                  while( true ) {
                    if (0x10799277 < (int)ppcVar8) {
                      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\schedmd.c",0x9e3);
                    }
                    if (*ppcVar8 == pcVar1->storage) break;
                    iVar6 = iVar6 + 1;
                    ppcVar8 = ppcVar8 + 1;
                  }
                  sched_fp_mark_pair((int)ctx,iVar6 - iVar9,pcVar7->rank);
                  (pcVar7->u18).reg = g_reg_symbols + pcVar7->rank + 0x1f;
                  pcVar12 = local_c;
                  pcVar2 = local_c;
                }
              }
            }
            local_c = pcVar2;
            pcVar7 = pcVar7->next;
            sVar4 = local_8;
          } while (pcVar7 != (c2_operand *)0x0);
          if (pcVar12 != (c2_operand *)0x0) {
            iVar9 = (int)g_sched_fp_tos;
            ppcVar8 = g_sched_fp_stack + iVar9;
            iVar6 = iVar9;
            while( true ) {
              if (0x10799277 < (int)ppcVar8) {
                ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\schedmd.c",0x9e3);
              }
              if (*ppcVar8 == pcVar12->sym->storage) break;
              iVar6 = iVar6 + 1;
              ppcVar8 = ppcVar8 + 1;
            }
            sched_fp_mark_pair((int)ctx,iVar6 - iVar9,0);
            (pcVar12->u18).reg = g_reg_symbols + 0x1f;
          }
        }
        local_8 = g_sched_fp_tos + local_8;
        iVar6 = 0;
        pcVar7 = ctx->dst;
        pcVar12 = pcVar7;
        g_sched_fp_tos = local_8;
        if (pcVar7 != (c2_operand *)0x0) {
          do {
            if ((pcVar12->kind == '\x01') &&
               ((((pcVar12->sym->cls == '\x03' && (pcVar12->sym->def != (c2_tuple *)0x0)) &&
                 ((pcVar12->type & 0xf000) == 0x4000)) || (ctx->op == 0x60)))) {
              iVar6 = iVar6 + 1;
              if (ctx->op != 0x19e) {
                local_8 = local_8 + -1;
                g_sched_fp_stack[local_8] = pcVar12->sym->storage;
              }
              (pcVar12->u18).reg = g_reg_symbols + pcVar12->rank + 0x1f;
            }
            ppcVar3 = &pcVar12->next;
            pcVar12 = *ppcVar3;
          } while (*ppcVar3 != (c2_operand *)0x0);
          g_sched_fp_tos = local_8;
          if (1 < iVar6) {
            (pcVar7->u18).reg = g_reg_symbols + 0x20;
            pcVar12 = pcVar7->next;
            g_sched_fp_stack[local_8 + 1] = pcVar7->sym->storage;
            (pcVar12->u18).reg = (c2_symbol *)0x107ad15c;
            g_sched_fp_stack[local_8] = pcVar12->sym->storage;
          }
        }
      }
      else {
        iVar10 = (int)g_sched_fp_tos;
        ppcVar8 = g_sched_fp_stack + iVar10;
        iVar9 = iVar10;
        while( true ) {
          if (0x10799277 < (int)ppcVar8) {
            ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\schedmd.c",0x9e3);
          }
          if (*ppcVar8 == pcVar1->storage) break;
          iVar9 = iVar9 + 1;
          ppcVar8 = ppcVar8 + 1;
        }
        iVar9 = iVar9 - iVar10;
        if ((iVar9 == 0) && (iVar6 < 0)) {
          sched_fp_mark_pair((int)ctx,0,1);
          iVar9 = 1;
        }
        uVar5 = pcVar7->type;
        (pcVar12->u18).reg = g_reg_symbols + iVar9 + 0x1f;
        if ((uVar5 & 0xf000) == 0x4000) {
          iVar10 = (int)g_sched_fp_tos;
          pcVar1 = pcVar12->sym;
          (pcVar7->u18).reg = g_reg_symbols + iVar9 + 0x1f;
          ppcVar8 = g_sched_fp_stack + iVar10;
          while( true ) {
            if (0x10799277 < (int)ppcVar8) {
              ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\schedmd.c",0x9e3);
            }
            if (*ppcVar8 == pcVar1->storage) break;
            iVar10 = iVar10 + 1;
            ppcVar8 = ppcVar8 + 1;
          }
          g_sched_fp_stack[iVar10] = pcVar7->sym->storage;
        }
        iVar11 = (int)g_sched_fp_tos;
        ppcVar8 = g_sched_fp_stack + iVar11;
        iVar10 = iVar11;
        if (iVar9 == 0) {
          while( true ) {
            if (0x10799277 < (int)ppcVar8) {
              ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\schedmd.c",0x9e3);
            }
            if (*ppcVar8 == pcVar2->sym->storage) break;
            iVar10 = iVar10 + 1;
            ppcVar8 = ppcVar8 + 1;
          }
          (pcVar2->u18).reg = (c2_symbol *)((iVar10 - iVar11) * 0x54 + 0x107ad15c);
        }
        else {
          while( true ) {
            if (0x10799277 < (int)ppcVar8) {
              ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\schedmd.c",0x9e3);
            }
            if (*ppcVar8 == pcVar2->sym->storage) break;
            iVar10 = iVar10 + 1;
            ppcVar8 = ppcVar8 + 1;
          }
          sched_fp_insert_fxch(ctx,iVar10 - iVar11);
          (pcVar2->u18).reg = (c2_symbol *)0x107ad15c;
        }
        g_sched_fp_tos = g_sched_fp_tos - (short)iVar6;
        if ((iVar6 < 0) && (((pcVar7->u18).reg)->id != 0x1f)) {
          pcVar7 = operand_new_hardreg(0x1f,pcVar7->type);
          tuple_append_dst(ctx,pcVar7);
        }
      }
    }
LAB_1077ac99:
    ctx = ctx->next;
  } while( true );
}

