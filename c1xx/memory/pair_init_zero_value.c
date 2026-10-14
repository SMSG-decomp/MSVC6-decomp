fe_name * __cdecl pair_init_zero_value(fe_name *out,char *text)

{
  out->next = (fe_name *)0x0;
  out->text = text;
  return out;
}

