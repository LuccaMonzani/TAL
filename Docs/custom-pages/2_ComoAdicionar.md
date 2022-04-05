# Como adicionar a TAL ao seu projeto

Crie um projeto qualquer no CubeIDE, abra a pasta dele no prompt e torne ele um repositório git com o seguinte comando

    git init

Logo então adicione a TAL com o comando 

    git submodule add https://github.com/EESC-USP-TUPA/TAL.git

No cube IDE a seguinte pasta deve ter aparecido

![Pasta da TAL](https://cdn.discordapp.com/attachments/898379907791482890/954157113242972190/unknown.png)

Para compilar são necessários dois passos extras

O primeiro deles é clicar com o botão direito na pasta TAL, ir em propriedades->C/C++ Build e desmarcar a seguinte caixa

![Colocando a pasta como target de build](https://cdn.discordapp.com/attachments/898379907791482890/954157617469591622/unknown.png)

Então você deve adicionar a pasta TAL/Inc nos caminhos de include, assim como mostra na foto

![Colocando a pasta Inc nos caminhos de include](https://cdn.discordapp.com/attachments/898379907791482890/954158106387046510/unknown.png)