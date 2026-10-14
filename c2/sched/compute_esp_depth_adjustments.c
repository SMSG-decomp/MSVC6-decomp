void __fastcall compute_esp_depth_adjustments(c2_function *fn)

{
  uint8_t uVar1;
  c2_tuple *t;
  c2_tuple *pcVar2;
  bool bVar3;
  c2_tuple *pcVar4;
  int esp_depth;
  
  t = fn->cfg->first->head;
  for (pcVar2 = t; pcVar2 != (c2_tuple *)0x0; pcVar2 = pcVar2->next) {
    pcVar2->flags12 = '\0';
  }
  bVar3 = false;
  esp_depth = 0;
  do {
    while( true ) {
      if (t == (c2_tuple *)0x0) {
        return;
      }
      pcVar2 = t->next;
      if (t->kind == '\x0f') {
        return;
      }
      if (t->kind == '\x1a') break;
      esp_depth = esp_depth_after_tuple(t,esp_depth);
      t->flags12 = '\x01';
      bVar3 = true;
      t = pcVar2;
    }
    pcVar4 = tuple_prev_real(t);
    if (t->flags12 != '\0') {
      return;
    }
    if ((pcVar4 != (c2_tuple *)0x0) && (bVar3)) {
      uVar1 = pcVar4->kind;
      if ((uVar1 == '\x11') &&
         (((pcVar4->u20).cond_cells == (c2_cond_cell *)0x0 && (pcVar4->op != 0x18b)))) {
        return;
      }
      if (uVar1 == '\x0f') {
        return;
      }
      if (uVar1 == '\x13') {
        return;
      }
    }
    t->flags12 = '\x01';
    *(int *)((int)&t->src[1].op + 2) = esp_depth;
    t = pcVar2;
  } while( true );
}

