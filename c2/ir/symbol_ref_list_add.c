void __fastcall symbol_ref_list_add(c2_list_cell **list,c2_fe_symbol *s)

{
  c2_list_cell *cell;
  c2_list_cell *old_head;
  
  if ((s->flags31 & 8) == 0) {
    s->flags31 = (g_inlining_active == 0) << 3 | s->flags31 & 0xf7;
    cell = arena_alloc(1,8);
    old_head = *list;
    (cell->u04).fe = s;
    cell->next = old_head;
    *list = cell;
  }
  return;
}

