void __fastcall sym_note_reference_from_function(c1_symbol *func,c1_symbol *init_sym,c1_symbol *sym)

{
  int *piVar1;
  void **cell_2;
  c1_symbol *pcVar2;
  void **cell;
  void *old_head;
  
  piVar1 = (init_sym->tail).data.dependents;
  if (piVar1 == (int *)0x0) {
    pcVar2 = (c1_symbol *)0x0;
  }
  else {
    pcVar2 = (c1_symbol *)*piVar1;
  }
  if (pcVar2 != func) {
    cell = arena_alloc(g_arenas,8);
    pcVar2 = g_current_function;
    cell[1] = piVar1;
    *cell = pcVar2;
    (g_init_symbol->tail).data.dependents = cell;
    func = g_current_function;
  }
  old_head = (void *)((func->tail).fn.record)->unk14;
  cell_2 = arena_alloc(g_arenas,8);
  *cell_2 = sym;
  cell_2[1] = old_head;
  ((g_current_function->tail).fn.record)->unk14 = (c1_u32)cell_2;
  return;
}

