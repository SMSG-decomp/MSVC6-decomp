int __cdecl option_goes_to_pass(optrec *opt,passrec *pass)

{
  char *hit;
  
  hit = strchr(opt->passes,(uint)(byte)pass->letter);
  return (uint)(hit != (char *)0x0);
}

