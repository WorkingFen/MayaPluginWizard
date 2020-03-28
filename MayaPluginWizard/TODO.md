# Things to do before using wizard
##### Project/Item

1. Create your project to whom you would like to create wizard
2. Make sure, to create **.zip** file with proper **.vstemplate**

##### Wizard

1. Find the *source.extension.vsixmanifest* file. Open it and select the **Assets** tab on the left side of the window.
2. Select **New** and in **Add New Asset** window, for the Type field, select **Microsoft.VisualStudio.(Project|Item)Template**. In the **Source** field, select **File on filesystem**. In the **Path** field, select proper path to your **.zip** file. Then click **OK**.
3. Sign the assembly. Go to **Project Properties** and select the **Signing** tab. In the **Signing** tab, check **Sign the assembly**. In the **Choose a strong name key file** field, select <**New**>. In the **Key file name** field, type **key.snk**. Uncheck the **Protect my key file with a password** field.
4. Rebuild project.
5. Copy the *key.snk* file from project directory and paste to *./bin/Debug*
6. Open *cmd* in directory in which the assembly has been created.
7. Find the *sn.exe* signing tool. For example, on a Windows 10 64-bit operating system, a typical path would be the following:

    *C:\Program Files(x86)\Microsoft SDKs\Windows\v10.0A\bin\NETFX 4.6.1 Tools*

    If you can't find it, try running **where /R . sn.exe** in the command window. Make a note of the path.
8. Extract the public key from the *key.snk* file. In the command window, type

    **\<location of sn.exe\>\sn.exe -p key.snk outfile.key**.

    Don't forget to surround the path of *sn.exe* with quotation marks if there are spaces in the directory names!
9. Get the public key token from the outfile:

    **\<location of sn.exe\>\sn.exe -t outfile.key**.

    Again, don't forget the quotation marks. You should see a line in the output like this

    **Public key token is \<token\>**

    Make a note of this value.
10. Add the reference to the custom wizard to the *.vstemplate* file in *.zip* file located in *./(Project|Item)Templates*. After the end of the \<TemplateContent\> section, add the following section:

    ```xml
    <WizardExtension>
        <Assembly>MayaPluginWizard, Version=1.0.0.0, Culture=Neutral, PublicKeyToken=token</Assembly>
        <FullClassName>MayaPluginWizard.WizardImplementation</FullClassName>
    </WizardExtension>
    ```
11. Save file to *.zip*
12. If you want to set category to your new template, click with right button **(Project|Item)Templates** in **Solution Explorer** and *Add* **New Folder** inside. Set its name to category name.
13. Move *.zip* file into new folder.
14. Open *source.extension.vsixmanifest* file as a code and find *Asset* with type of **(Project|Item)Template**. Change **d:TargetPath** by adding category.
15. Rebuild project with *Release* configuration.
16. Change description of *source.extension.vsixmanifest* file.
17. After creating proper wizard you need to add Post-Build Event. Go to **Project Properties** and select the **Build Events** tab. In **Post-build event command line** copy-paste this snippet of code:

    ```batch
    if not exist "$(SolutionDir)VSIX" mkdir "$(SolutionDir)VSIX"
    xcopy /y /c /f "$(ProjectDir)$(OutDir)$(ProjectName).vsix" "$(SolutionDir)VSIX"
    ```

> Manual based on [How to: Use wizards with project templates](https://docs.microsoft.com/en-gb/visualstudio/extensibility/how-to-use-wizards-with-project-templates?view=vs-2017)