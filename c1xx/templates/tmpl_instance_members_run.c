void __fastcall tmpl_instance_members_run(c1_tmpl_work_item *item)

{
  byte bVar1;
  bool bVar2;
  c1xx_scope **ppcVar3;
  c1_scope_stack *pcVar4;
  char cVar5;
  c1_symbol *pcVar6;
  uint uVar7;
  c1_decl_state *pcVar8;
  byte bVar9;
  c1_symbol *pcVar10;
  char pushed_state;
  uint explicit_flag;
  c1_member_iter statics_iter;
  c1_member_iter functions_iter;
  c1xx_ovl_set_iter overload_iter;
  
  pcVar4 = g_current_scope;
  pushed_state = '\0';
  if (g_current_scope->current != g_current_scope->global_scope) {
    pcVar8 = arena_alloc(g_arenas + 8,0x1c);
    if (pcVar8 == (c1_decl_state *)0x0) {
      pcVar8 = (c1_decl_state *)0x0;
    }
    else {
      pcVar8 = decl_state_snapshot(pcVar8,pcVar4,pcVar4->saved,'\x01');
    }
    pcVar4->saved = pcVar8;
    pcVar4 = g_current_scope;
    pushed_state = '\x01';
    ppcVar3 = &g_current_scope->global_scope;
    g_current_scope->depth = '\0';
    pcVar4->current = *ppcVar3;
    pcVar4->qual_class = (c1_symbol *)0x0;
    pcVar4->access_op = '\x01';
    pcVar4->qualified = '\0';
    pcVar4->reported = '\0';
    pcVar4->keep_aliases = '\0';
  }
  if (item->sym == (c1_symbol *)0x0) {
    diag_fatal(1,".\\template.cpp",0x342);
  }
  item->armed = '\0';
  if ((item->sym->flags3 & 4) == 0) {
    class_member_iter_init(&functions_iter,&item->sym->name,2);
    ovl_set_iter_init(&overload_iter,(void *)0x0);
    class_member_iter_init(&statics_iter,&item->sym->name,1);
LAB_1044324e:
    cVar5 = sym_overload_iter_next(&overload_iter);
    if (cVar5 != '\0') {
      pcVar6 = (c1_symbol *)&overload_iter.current[-1].position;
      bVar9 = (byte)overload_iter.current[-1].position & 0x1f;
      pcVar10 = pcVar6;
      if (bVar9 == 0x1a) {
        pcVar10 = (((overload_iter.current)->type).alias)->target;
      }
      if ((pcVar10->flags3 & 4) == 0) {
        pcVar10 = pcVar6;
        if (bVar9 == 0x1a) {
          pcVar10 = (((overload_iter.current)->type).alias)->target;
        }
        if ((*(c1_u32 *)&pcVar10->kind & 0x1f) != 7) {
          pcVar10 = pcVar6;
          if (bVar9 == 0x1a) {
            pcVar10 = (((overload_iter.current)->type).alias)->target;
          }
          if ((*(c1_u32 *)&pcVar10->kind & 0x1f) != 8) goto LAB_1044324e;
        }
        pcVar10 = pcVar6;
        if (bVar9 == 0x1a) {
          pcVar10 = (((overload_iter.current)->type).alias)->target;
        }
        if ((pcVar10->flags22 & 0x20) == 0) {
          bVar2 = false;
          uVar7 = explicit_flag >> 8;
          explicit_flag = explicit_flag & 0xffffff00;
          pcVar10 = pcVar6;
          if (bVar9 == 0x1a) {
            pcVar10 = (((overload_iter.current)->type).alias)->target;
          }
          if ((pcVar10->flags22 & 8) == 0) {
            pcVar10 = pcVar6;
            if (bVar9 == 0x1a) {
              pcVar10 = (((overload_iter.current)->type).alias)->target;
            }
            if ((((pcVar10->flags22 & 0x10) != 0) ||
                ((((item->sym->detail).cls)->flags3e & 0x10) != 0)) || (g_opt_BforceInst != '\0')) {
              if (bVar9 == 0x1a) {
                pcVar6 = (((overload_iter.current)->type).alias)->target;
              }
              bVar2 = true;
              explicit_flag = CONCAT31((int3)uVar7,1);
              pcVar6->flags21 = pcVar6->flags21 | 0x80;
            }
          }
          pcVar6 = (c1_symbol *)&overload_iter.current[-1].position;
          bVar9 = (byte)overload_iter.current[-1].position & 0x1f;
          pcVar10 = pcVar6;
          if (bVar9 == 0x1a) {
            pcVar10 = (((overload_iter.current)->type).alias)->target;
          }
          if ((pcVar10->flags2 & 4) == 0) {
            pcVar10 = pcVar6;
            if (bVar9 == 0x1a) {
              pcVar10 = (((overload_iter.current)->type).alias)->target;
            }
            if ((pcVar10->flags3 & 1) == 0) {
              pcVar10 = pcVar6;
              if (bVar9 == 0x1a) {
                pcVar10 = (((overload_iter.current)->type).alias)->target;
              }
              if ((*(byte *)((int)&pcVar10->tail + 9) & 0x40) == 0) {
                if (!bVar2) {
                  bVar1 = ((item->sym->detail).cls)->flags3e;
                  if ((bVar1 & 0x20) != 0) goto LAB_1044324e;
                  pcVar10 = pcVar6;
                  if (bVar9 == 0x1a) {
                    pcVar10 = (((overload_iter.current)->type).alias)->target;
                  }
                  if ((pcVar10->key_ref & 3) == 0) {
                    pcVar10 = pcVar6;
                    if (bVar9 == 0x1a) {
                      pcVar10 = (((overload_iter.current)->type).alias)->target;
                    }
                    if (((pcVar10->flags21 & 2) == 0) && ((bVar1 & 0x10) == 0)) goto LAB_1044324e;
                  }
                }
                if (bVar9 == 0x1a) {
                  pcVar6 = (((overload_iter.current)->type).alias)->target;
                }
                cVar5 = tmpl_instantiate_instance_member(item->sym,pcVar6,(char)explicit_flag);
                if (cVar5 != '\0') {
                  item->armed = '\x01';
                }
              }
            }
          }
        }
      }
      goto LAB_1044324e;
    }
    cVar5 = class_member_iter_next(&functions_iter);
    if (cVar5 != '\0') {
      sym_overload_iter_init(&overload_iter,functions_iter.current);
      goto LAB_1044324e;
    }
    while (statics_iter.current = statics_iter.next, statics_iter.next != (void *)0x0) {
      if ((statics_iter.cursor.current == (void *)0x0) ||
         (statics_iter.cursor.current = *(void **)((int)statics_iter.cursor.current + 4),
         statics_iter.next = statics_iter.cursor.current, statics_iter.cursor.current == (void *)0x0
         )) {
        statics_iter.next = (void *)0x0;
      }
      uVar7 = class_member_iter_matches(&statics_iter);
      if ((((char)uVar7 != '\0') && ((*(byte *)((int)statics_iter.current + -5) & 4) == 0)) &&
         ((*(byte *)((int)statics_iter.current + 0x18) & 7) == 3)) {
        tmpl_instance_static_member_fragment
                  ((int)statics_iter.current,0,item,pushed_state,explicit_flag,
                   (int)statics_iter.cursor.current,(int)statics_iter.current,(int)statics_iter.next
                  );
        return;
      }
    }
    statics_iter.next = (void *)0x0;
    statics_iter.current = (void *)0x0;
  }
  if (pushed_state != '\0') {
    decl_state_restore(g_current_scope,'\x01');
    decl_state_pop(g_current_scope);
  }
  return;
}

