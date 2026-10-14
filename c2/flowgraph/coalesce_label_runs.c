void __fastcall coalesce_label_runs(c2_function *fn)

{
  c2_tuple *pcVar1;
  bool bVar2;
  c2_tuple *t;
  c2_tuple *t_00;
  c2_tuple *t2;
  c2_tuple *pcVar3;
  uint32_t uVar4;
  uint32_t local_8;
  c2_tuple *local_4;
  
  bVar2 = false;
  pcVar1 = fn->cfg->first->head;
  t_00 = local_4;
  pcVar3 = local_4;
  while (t2 = pcVar3, t = pcVar1, t != (c2_tuple *)0x0) {
    pcVar1 = t->next;
    pcVar3 = t2;
    if (t->kind != '\x16') {
      if (t->kind == '\x1a') {
        if (bVar2) {
          uVar4 = label_is_removable(t);
          pcVar3 = t;
          if (uVar4 != 0) {
            if (local_8 == 0) {
              local_8 = 1;
              local_4 = t;
            }
            else {
              if (t2 != (c2_tuple *)0x0) {
                merge_label_run(t_00,t2,local_4);
              }
              local_4 = t;
              t_00 = t;
              pcVar3 = (c2_tuple *)0x0;
            }
          }
        }
        else {
          bVar2 = true;
          local_8 = label_is_removable(t);
          local_4 = t;
          t_00 = t;
          pcVar3 = (c2_tuple *)0x0;
        }
      }
      else if (bVar2) {
        if (t2 != (c2_tuple *)0x0) {
          merge_label_run(t_00,t2,local_4);
        }
        bVar2 = false;
      }
    }
  }
  return;
}

