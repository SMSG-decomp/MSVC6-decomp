c2_node * __fastcall factor_strip_ops(c2_node *n)

{
  if (n->op == g_factor_lookthrough_op) {
    n = *(c2_node **)&n[1].kind;
  }
  if (n->op == g_factor_inner_op) {
    if ((g_factor_inner_op == 0x171) || (g_factor_inner_op == 0x177)) {
      n = (c2_node *)**(undefined4 **)&n[1].kind;
    }
    else {
      n = *(c2_node **)&n[1].kind;
    }
    if (n->op == g_factor_lookthrough_op) {
      n = *(c2_node **)&n[1].kind;
    }
  }
  return n;
}

