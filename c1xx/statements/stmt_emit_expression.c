void __cdecl stmt_emit_expression(c1_node *node)

{
  c1_u16 cVar1;
  byte bVar2;
  char cVar3;
  c1_node *pcVar4;
  c1_symbol *sym;
  
  if (g_error_count == 0) {
    if ((node == (c1_node *)0x0) || ((cVar1 = node->type->code, cVar1 != 0x80c && (cVar1 != 0x80e)))
       ) {
      il_emit_pragma_or_segment_record(0x24);
      il_emit_expression_tree(node);
      il_emit_tuple(0x4b,(node *)0x0);
    }
    else {
      pcVar4 = tree_strip_address_of(node);
      if (pcVar4->op == 'S') {
        sym = *(c1_symbol **)(**(int **)(*(int *)((int)pcVar4->right + 0x10) + 0x14) + 8);
      }
      else {
        if (pcVar4->op != '\x06') {
          return;
        }
        sym = pcVar4->left;
      }
      if (((sym != (c1_symbol *)0x0) &&
          (((((bVar2 = sym->kind & 0x1f, bVar2 == 0x10 || (bVar2 == 7)) || (bVar2 == 6)) ||
            (((bVar2 == 0x11 || (bVar2 == 8)) || (bVar2 == 0x1b)))) ||
           ((bVar2 == 0x1a &&
            (((bVar2 = **(byte **)sym->type & 0x1f, bVar2 == 0x10 || (bVar2 == 7)) ||
             ((bVar2 == 6 || (((bVar2 == 0x11 || (bVar2 == 8)) || (bVar2 == 0x1b)))))))))))) &&
         (cVar3 = ovl_names_single_function(sym,'\x01'), cVar3 == '\0')) {
        diag_error(0x238,(uint)pcVar4->op,sym);
        return;
      }
    }
  }
  return;
}

