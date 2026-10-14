int __fastcall analyze_return_paths(c2_function *fn)

{
  uint8_t uVar1;
  c2_block *pcVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  c2_tuple *t;
  c2_tuple *t_00;
  c2_edge *pcVar6;
  uint uVar7;
  uint32_t uVar8;
  c2_block *pcVar9;
  int local_8;
  
  pcVar2 = fn->cfg->first;
  local_8 = 0;
  pcVar9 = pcVar2;
  do {
    if (pcVar9 == (c2_block *)0x0) {
      do {
        bVar4 = false;
        pcVar9 = pcVar2;
        if (pcVar2 == (c2_block *)0x0) {
          return local_8;
        }
        do {
          if (((pcVar9->flags & 0x1000) == 0) && (pcVar6 = pcVar9->preds, pcVar6 != (c2_edge *)0x0))
          {
            bVar3 = true;
            do {
              if (((pcVar6->flags & 0x40) == 0) && (bVar3 = false, (pcVar6->flags & 0x1000) == 0)) {
                if (pcVar6 == (c2_edge *)0x0) goto LAB_107333d1;
                goto LAB_107333a1;
              }
              pcVar6 = pcVar6->next_pred;
            } while (pcVar6 != (c2_edge *)0x0);
            if (bVar3) {
LAB_1073337d:
              if ((pcVar9->flags & 2) != 0) {
                for (pcVar6 = pcVar9->succs; pcVar6 != (c2_edge *)0x0; pcVar6 = pcVar6->next_succ) {
                  if ((pcVar6->flags & 0x40) == 0) {
                    bVar4 = true;
                    pcVar6->flags = pcVar6->flags | 0x40;
                  }
                }
              }
            }
            else {
LAB_107333d1:
              pcVar6 = pcVar9->succs;
              bVar4 = true;
              pcVar9->flags = pcVar9->flags | 0x1000;
              if (pcVar6 != (c2_edge *)0x0) {
                do {
                  pcVar6->flags = pcVar6->flags | 0x1000;
                  pcVar6 = pcVar6->next_succ;
                } while (pcVar6 != (c2_edge *)0x0);
                if (bVar3) goto LAB_1073337d;
              }
            }
          }
LAB_107333a1:
          pcVar9 = pcVar9->next;
        } while (pcVar9 != (c2_block *)0x0);
        if (!bVar4) {
          return local_8;
        }
      } while( true );
    }
    uVar7 = pcVar9->flags & 0xfffffffd;
    pcVar9->flags = uVar7;
    t = tuple_prev_real_before_boundary(pcVar9->end);
    if (t == (c2_tuple *)0x0) {
LAB_10733341:
      pcVar9->flags = uVar7 | 2;
LAB_1073329d:
      if ((pcVar9->flags & 1) == 0) goto LAB_10733359;
      pcVar9->flags = pcVar9->flags & 0xffffefff;
    }
    else {
      t_00 = t;
      if (((t->kind == '\x11') && ((t->u20).cond_cells == (c2_cond_cell *)0x0)) && (t->op != 0x18b))
      {
        t_00 = tuple_prev_real_before_boundary(t);
      }
      if (t_00 == (c2_tuple *)0x0) goto LAB_10733341;
      uVar1 = t_00->kind;
      while (uVar1 != '\x19') {
        iVar5 = tuple_sets_return_value(t_00);
        if (iVar5 != 0) {
          local_8 = 1;
          break;
        }
        t_00 = t_00->prev;
        uVar1 = t_00->kind;
      }
      if ((t_00 == (c2_tuple *)0x0) || (t_00->kind == '\x19')) goto LAB_1073329d;
LAB_10733359:
      pcVar9->flags = pcVar9->flags | 0x1000;
    }
    for (pcVar6 = pcVar9->succs; pcVar6 != (c2_edge *)0x0; pcVar6 = pcVar6->next_succ) {
      uVar7 = pcVar6->flags;
      pcVar6->flags = uVar7 & 0xffffffbf;
      if (((uVar7 & 1) == 0) || ((pcVar9->flags & 0x1000) != 0)) {
        uVar8 = uVar7 & 0xffffffbf | 0x1000;
      }
      else {
        uVar8 = uVar7 & 0xffffefbf;
      }
      pcVar6->flags = uVar8;
    }
    mark_abnormal_edges(t,pcVar9);
    pcVar9 = pcVar9->next;
  } while( true );
}

