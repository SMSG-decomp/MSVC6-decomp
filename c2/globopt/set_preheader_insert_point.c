void __fastcall set_preheader_insert_point(c2_loop *loop)

{
  g_preheader_insert_point = loop->preheader->end;
  return;
}

