void __fastcall pass_if_convert(c2_function *fn)

{
  c2_tuple *branch;
  
  for (branch = fn->cfg->first->head; branch != (c2_tuple *)0x0; branch = branch->next) {
    if ((branch->kind == '\x11') &&
       ((((branch->u20).cond_cells != (c2_cond_cell *)0x0 || (branch->op == 0x18b)) &&
        ((branch->flags & 8) == 0)))) {
      branch = try_if_convert_diamond(fn,branch);
    }
  }
  return;
}

